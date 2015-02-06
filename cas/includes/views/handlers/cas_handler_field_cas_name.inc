<?php

/**
 * @file
 * Field handler to provide a list of CAS user names.
 */

/**
 * Field handler to provide a list of CAS user names.
 */
class cas_handler_field_cas_name extends views_handler_field_prerender_list {
  function construct() {
    parent::construct();
    $this->additional_fields['uid'] = array('table' => 'users', 'field' => 'uid');
  }

  function query() {
    $this->add_additional_fields();
    $this->field_alias = $this->aliases['uid'];
  }

  function pre_render($values) {
    $uids = array();
    $this->items = array();

    foreach ($values as $result) {
      $uids[] = $result->{$this->aliases['uid']};
    }

    if ($uids) {
      $result = db_query("SELECT aid, uid, cas_name FROM {cas_user} WHERE uid IN (" . implode(', ', $uids) . ")");
      while ($cas_user = db_fetch_object($result)) {
        $this->items[$cas_user->uid][$cas_user->aid]['cas_name'] = check_plain($cas_user->cas_name);
      }
    }
  }

  function render_item($count, $item) {
    return $item['cas_name'];
  }
}
