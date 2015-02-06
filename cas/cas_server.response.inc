<?php

/**
 * @file
 * Response callbacks for the CAS Server module.
 */

/**
 * Returns a CAS 2.0 service response for a validation success.
 *
 * @param $name
 *   CAS username.
 * @param $attributes
 *   If specified, the CAS attributes for the user.
 */
function theme_cas_service_validate_success($name, $attributes = array(), $style = 'jasig') {
  $output = "<cas:serviceResponse xmlns:cas='http://www.yale.edu/tp/cas'>\n";
  $output .= "<cas:authenticationSuccess>\n";
  $output .= "<cas:user>$name</cas:user>\n";
  $output .= theme('cas_service_validate_attributes', $attributes, $style);
  $output .= "</cas:authenticationSuccess>\n";
  $output .= "</cas:serviceResponse>\n";

  return $output;
}

/**
 * Returns CAS attributes as part of a CAS 2.0 service response.
 *
 * @param $attributes
 *  The CAS attributes for the user
 * @param $style
 *   Must be one of:
 *     - 'jasig' (default)
 *     - 'rubycas'
 *     - 'name-value'
 */
function theme_cas_service_validate_attributes($attributes = array(), $style = 'jasig') {
  $output = '';
  switch ($style) {
    case 'jasig':
    default:
      $output .= "<cas:attributes>\n";
      $output .= "<cas:attraStyle>Jasig</cas:attraStyle>\n";
      foreach ($attributes as $name => $values) {
        foreach ((array) $values as $value) {
          $output .= strtr("<cas:!name>!value</cas:!name>\n", array('!name' => $name, '!value' => $value));
        }
      }
      $output .= "</cas:attributes>\n";
      break;
    case 'rubycas':
      $output .= "<cas:attraStyle>RubyCAS</cas:attraStyle>\n";
      foreach ($attributes as $name => $values) {
        foreach ((array) $values as $value) {
          $output .= strtr("<cas:!name>!value</cas:!name>\n", array('!name' => $name, '!value' => $value));
        }
      }
      break;
    case 'name-value':
      $output .= "<cas:attribute name='attraStyle' value='Name-Value' />\n";
      foreach ($attributes as $name => $values) {
        foreach ((array) $values as $value) {
          $output .= strtr("<cas:attribute name='!name' value='!value' />\n", array('!name' => $name, '!value' => $value));
        }
      }
      break;
  }

  return $output;
}


/**
 * Returns a CAS 2.0 service response for a validation failure.
 *
 * @param $ticket
 * @param $error_code
 */
function theme_cas_service_validate_failure($ticket, $error_code) {
  $output = "<cas:serviceResponse xmlns:cas='http://www.yale.edu/tp/cas'>\n";
  $output .= "<cas:authenticationFailure code=\"$error_code\">\n";
  $output .= "Ticket $ticket not recognized.\n";
  $output .= "</cas:authenticationFailure>\n";
  $output .= "</cas:serviceResponse>\n";

  return $output;
}


/**
 * Generate the Single Sign Out request.
 *
 * @param unknown_type $variables
 *   An associative array containing the key, date and logout id request
 */
function theme_cas_service_logout_request($ticket, $date, $id) {
  $output = "<samlp:LogoutRequest xmlns:samlp='urn:oasis:names:tc:SAML:2.0:protocol' ID='$id' Version='2.0' IssueInstant='$date'>\n";
  $output .= "<saml:NameID xmlns:saml='urn:oasis:names:tc:SAML:2.0:assertion'>@NOT_USED@</saml:NameID>\n";
  $output .= "<samlp:SessionIndex>$ticket</samlp:SessionIndex>\n";
  $output .= "</samlp:LogoutRequest>\n";
  return $output;
}
