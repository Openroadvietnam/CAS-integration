<?php

/**
 * @file
 *  Link general CAS user functionalities to services module.
 */


/**
 * Get CAS username
 *
 * @param $uid
 *   UID of the user to be loaded.
 *
 */
function cas_user_service_get($uid) {
  $result = db_query('SELECT aid, cas_name FROM {cas_user} WHERE uid = %d', $uid);  
  
  $account->cas_names = array();
  while ($record = db_fetch_object($result)) {
    $account->cas_names[$record->aid] = $record->cas_name;
  }
  
  reset($account->cas_names);  
  $account->cas_name = current($account->cas_names);

  if (!$account->cas_name) {
    return services_error(t('There is no user with such ID.'), 404);
  }

  // Everything went right.
  return $account;
}
 


/**
 * Check if the user is allowed to get the CAS username
 */
function cas_user_service_get_access() {
  return (user_access('get any CAS user data'));
}



/**
 * Save CAS username.
 * 
 * @param $account
 *   An array of account information.
 *
 */
function cas_user_service_save($uid, $cas_name) {
  // UID gets returned as a string if its passed in an array, see bug    
  // http://drupal.org/node/1224470 
      
  // check if this is an insert or update    
  $account_old = db_fetch_object(db_query('SELECT aid, cas_name, uid FROM {cas_user} WHERE uid = %d', $uid));

  //return array(array($uid, $cas_name), $account_old);
  //return $account_old;
  
  if (!$account_old) {
    db_query("INSERT INTO {cas_user} (uid, cas_name) VALUES (%d, '%s')", $uid, $cas_name);
  }
  else {
    db_query("UPDATE {cas_user} SET cas_name = '%s' WHERE uid = %d AND aid = %d", $cas_name, $uid, $account_old->aid);    
  }  

  // TODO maybe add some error checking

  // Everything went right.
  return TRUE;
}



/**
 * Check if the services account is allowed to edit CAS username
 */
function cas_user_service_save_access() {
  return (user_access('update any CAS user name'));
}

 
 
/**
 * Delete a CAS username.
 *
 * @param $uid
 *   UID of the user to be deleted.
 *
 */
function cas_user_service_delete($uid) {
  // Remove a CAS username.
  db_query("DELETE FROM {cas_user} WHERE uid = %d", $uid);
  
  $count = db_affected_rows();
  
  if ($count == 0) {
    return services_error(t('There is no user with such ID.'), 404);
  }

  // Everything went right.
  return TRUE;
}



/**
 * Check to see if the services account is allowed to delete a CAS username
 */
function cas_user_service_delete_access() {
  return (user_access('delete any user'));
}