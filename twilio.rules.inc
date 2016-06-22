<?php
/**
 * @file
 * Rules module integration
 */

/**
 * Implements hook_rules_data_info().
 */
function twilio_rules_data_info() {
  $defaults = array(
    'group' => t('Twilio'),
    'module' => 'twilio',
    'wrap' => TRUE,
  );

  $resource_properties = array(
    'Sid' => array(
      'type' => 'text',
      'label' => t('SID'),
      'description' => t('A 34 character string that uniquely identifies this resource.'),
    ),
    'AccountSid' => array(
      'type' => 'text',
      'label' => t('Account SID'),
      'description' => t('The unique id of the Account that owns this resource.'),
    ),
    'CallSid' => array(
      'type' => 'text',
      'label' => t('Call SID'),
      'description' => t('The unique id for the parent call leg that corresponds to the resource.'),
    ),
    'ConferenceSid' => array(
      'type' => 'text',
      'label' => t('Conference SID'),
      'description' => t('A 34 character string that identifies the conference this participant is in.'),
    ),
    'MessagingServiceSid' => array(
      'type' => 'text',
      'label' => t('Messaging Service SID'),
      'description' => t('The unique id of the Messaging Service used with the message. The value will be null if a Messaging Service was not used.'),
    ),
    'OwnerAccountSid' => array(
      'type' => 'text',
      'label' => t('Owner Account SID'),
      'description' => t('The Sid of the parent account for this account. The OwnerAccountSid of a parent account is its own sid.'),
    ),
    'ParentCallSid' => array(
      'type' => 'text',
      'label' => t('Parent Call SID'),
      'description' => t('A 34 character string that uniquely identifies the call that created this leg.'),
    ),
    'ParentSid' => array(
      'type' => 'text',
      'label' => t('Parent SID'),
      'description' => t('The uniqe id of the resource that created the media.'),
    ),
    'PhoneNumberSid' => array(
      'type' => 'text',
      'label' => t('Phone Number SID'),
      'description' => t('If the call was inbound, this is the Sid of the IncomingPhoneNumber that received the call. If the call was outbound, it is the Sid of the OutgoingCallerId from which the call was placed.'),
    ),
    'RecordingSid' => array(
      'type' => 'text',
      'label' => t('Recording SID'),
      'description' => t('The unique id of the Recording this Transcription was made of.'),
    ),
    'SmsApplicationSid' => array(
      'type' => 'text',
      'label' => t('SMS Application SID'),
      'description' => t('The 34 character sid of the application Twilio should use to handle SMSs sent to this number. If a SmsApplicationSid is present, Twilio will ignore all of the SMS urls above and use those set on the application.'),
    ),
    'TrunkSid' => array(
      'type' => 'text',
      'label' => t('Trunk SID'),
      'description' => t('The 34 character sid of the Trunk Twilio should use to handle phone calls to this number. If a TrunkSid is present, Twilio will ignore all of the voice urls and voice applications above and use those set on the Trunk. Setting a TrunkSid will automatically delete your VoiceApplicationSid and vice versa.'),
    ),
    'VoiceApplicationSid' => array(
      'type' => 'text',
      'label' => t('Voice Application SID'),
      'description' => t('The 34 character sid of the application Twilio should use to handle phone calls to this number. If a VoiceApplicationSid is present, Twilio will ignore all of the voice urls above and use those set on the application. Setting a VoiceApplicationSid will automatically delete your TrunkSid and vice versa.'),
    ),
    'CallbackMethod' => array(
      'type' => 'text',
      'label' => t('Callback Method'),
      'description' => t('The HTTP method Twilio will use when making a request to the CallbackUrl.'),
      'options list' => 'twilio_method_options_list',
    ),
    'CallbackUrl' => array(
      'type' => 'uri',
      'label' => t('Callback Url'),
      'description' => t('Twilio will make a request to this url when the trigger fires.'),
    ),
    'SmsFallbackMethod' => array(
      'type' => 'text',
      'label' => t('Sms Fallback Method'),
      'description' => t('The HTTP method Twilio will use when requesting the SmsFallbackUrl.'),
      'options list' => 'twilio_method_options_list',
    ),
    'SmsFallbackUrl' => array(
      'type' => 'uri',
      'label' => t('Sms Fallback Url'),
      'description' => t('The URL that Twilio will request if an error occurs retrieving or executing the TwiML from SmsUrl.'),
    ),
    'StatusCallback' => array(
      'type' => 'uri',
      'label' => t('Status Callback'),
      'description' => t('The URL that Twilio will request to pass status parameters (such as call ended) to your application.'),
    ),
    'StatusCallbackMethod' => array(
      'type' => 'text',
      'label' => t('Status Callback Method'),
      'description' => t('The HTTP method Twilio will use to make requests to the StatusCallback URL.'),
      'options list' => 'twilio_method_options_list',
    ),
    'VoiceFallbackMethod' => array(
      'type' => 'text',
      'label' => t('Voice Fallback Method'),
      'description' => t('The HTTP method Twilio will use when requesting the VoiceFallbackUrl.'),
      'options list' => 'twilio_method_options_list',
    ),
    'VoiceFallbackUrl' => array(
      'type' => 'uri',
      'label' => t('Voice Fallback Url'),
      'description' => t('The URL that Twilio will request if an error occurs retrieving or executing the TwiML requested by Url.'),
    ),
    'VoiceMethod' => array(
      'type' => 'text',
      'label' => t('Voice Method'),
      'description' => t('The HTTP method Twilio will use when requesting the VoiceUrl.'),
      'options list' => 'twilio_method_options_list',
    ),
    'VoiceUrl' => array(
      'type' => 'uri',
      'label' => t('Voice Url'),
      'description' => t('The URL Twilio will request when a phone number assigned to this application receives a call.'),
    ),
    'SmsMethod' => array(
      'type' => 'text',
      'label' => t('Sms Method'),
      'description' => t('The HTTP method Twilio will use when making requests to the SmsUrl.'),
      'options list' => 'twilio_method_options_list',
    ),
    'SmsUrl' => array(
      'type' => 'uri',
      'label' => t('Sms Url'),
      'description' => t('The URL Twilio will request when a phone number assigned to this application receives an incoming SMS message.'),
    ),
    'SmsStatusCallback' => array(
      'type' => 'uri',
      'label' => t('Sms Status Callback'),
      'description' => t('The URL that Twilio will POST to when a message is sent via the /SMS/Messages endpoint if you specify the Sid of this application on an outgoing SMS request.'),
    ),
    'MessageStatusCallback' => array(
      'type' => 'uri',
      'label' => t('Message Status Callback'),
      'description' => t('Twilio will make a POST request to this URL to pass status parameters (such as sent or failed) to your application if you use the /Messages endpoint to send the message and specify this application\'s Sid as the ApplicationSid on an outgoing SMS request.'),
    ),
    'Uri' => array(
      'type' => 'text',
      'label' => t('Uri'),
      'description' => t('The URI for this resource, relative to https://api.twilio.com.'),
    ),
    'SubresourceUri' => array(
      'type' => 'text',
      'label' => t('Subresource Uri'),
      'description' => t('The URIs for any subresources associate with this resource, relative to https://api.twilio.com'),
    ),
    'SubresourceUris' => array(
      'type' => 'text',
      'label' => t('Subresource Uris'),
      'description' => t('The URIs for any subresources associate with this resource, relative to https://api.twilio.com'),
    ),
    'UsageRecordUri' => array(
      'type' => 'text',
      'label' => t('Usage Record Uri'),
      'description' => t('The URI of the UsageRecord this trigger is watching, relative to https://api.twilio.com.'),
    ),
    'DateCreated' => array(
      'type' => 'date',
      'label' => t('Date Created'),
      'description' => t('The date that this resource was created.'),
    ),
    'DateEnqueued' => array(
      'type' => 'date',
      'label' => t('Date Enqueued'),
      'description' => t('The date that the member was enqueued.'),
    ),
    'DateFired' => array(
      'type' => 'date',
      'label' => t('Date Fired'),
      'description' => t('The date the trigger was last fired.'),
    ),
    'DateSent' => array(
      'type' => 'date',
      'label' => t('Date Sent'),
      'description' => t('The date that the message was sent. For incoming messages, this is the date that Twilio received the message.'),
    ),
    'DateUpdated' => array(
      'type' => 'date',
      'label' => t('Date Updated'),
      'description' => t('The date that this resource was last updated.'),
    ),
    'FriendlyName' => array(
      'type' => 'text',
      'label' => t('Friendly Name'),
      'description' => t('A human readable descriptive text for this resource, up to 64 characters long.'),
    ),
  );

  return array(
    'twilio_sms_request' => $defaults + array(
      'label' => t('Twilio incoming SMS'),
      'property info' => array(
        'number' => array(
          'type' => 'text',
          'label' => t('Number'),
          'description' => t('The phone number of the incoming SMS.'),
          'getter callback' => 'entity_property_verbatim_get',
          'setter callback' => 'entity_property_verbatim_set',
        ),
        'number_twilio' => array(
          'type' => 'text',
          'label' => t('Twilio Number'),
          'description' => t('The Twilio phone number that receieved the message.'),
          'getter callback' => 'entity_property_verbatim_get',
          'setter callback' => 'entity_property_verbatim_set',
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t('The message of the incoming SMS.'),
          'getter callback' => 'entity_property_verbatim_get',
          'setter callback' => 'entity_property_verbatim_set',
        ),
        'media' => array(
          'type' => 'text',
          'label' => t('Media'),
          'description' => t('The media attached to the incoming SMS.'),
          'getter callback' => 'entity_property_verbatim_get',
          'setter callback' => 'entity_property_verbatim_set',
        ),
      ),
    ),
    'twilio_call_instance' => $defaults + array(
      'label' => t('Twilio Call Instance'),
      'property info' => _twilio_map_options($resource_properties, array(
        'sid' => 'Sid',
        'date_created' => 'DateCreated',
        'date_updated' => 'DateUpdated',
        'account_sid' => 'AccountSid',
        'uri' => 'Uri',
        'parent_call_sid' => 'ParentCallSid',
        'to' => 'To',
        'from' => 'From',
        'phone_number_sid' => 'PhoneNumberSid',
        'status' => 'Status',
        'start_time' => 'StartTime',
        'end_time' => 'EndTime',
        'duration' => 'Duration',
        'price' => 'Price',
        'price_unit' => 'PriceUnit',
        'direction' => 'Direction',
        'answered_by' => 'AnsweredBy',
        'forwarded_from' => 'ForwardedFrom',
        'to_formatted' => 'ToFormatted',
        'from_formatted' => 'FromFormatted',
        'caller_name' => 'CallerName',
      )),
    ),
    'twilio_message_instance' => $defaults + array(
      'label' => t('Twilio Message Instance'),
      'property info' => _twilio_map_options($resource_properties, array(
        'sid' => 'Sid',
        'date_created' => 'DateCreated',
        'date_updated' => 'DateUpdated',
        'date_sent' => 'DateSent',
        'account_sid' => 'AccountSid',
        'messaging_service_sid' => 'MessagingServiceSid',
        'from' => 'From',
        'to' => 'To',
        'body' => 'Body',
        'num_media' => 'NumMedia',
        'num_segments' => 'NumSegments',
        'status' => 'Status',
        'error_code' => 'ErrorCode',
        'error_message' => 'ErrorMessage',
        'direction' => 'Direction',
        'price' => 'Price',
        'price_unit' => 'PriceUnit',
        'api_version' => 'ApiVersion',
        'uri' => 'Uri',
        'subresource_uri' => 'SubresourceUri',
      )),
    ),
    'twilio_voice_request' => $defaults + array(
      'label' => t('Twilio Incoming Voice request'),
      'property info' => array(
        'call_sid' => array(
          'type' => 'text',
          'label' => t('Call SID'),
          'description' => t('A unique identifier for this call, generated by Twilio.'),
        ),
        'account_sid' => array(
          'type' => 'text',
          'label' => t('Account SID'),
          'description' => t('The Twilio account id. It is 34 characters long, and always starts with the letters AC.'),
        ),
        'from' => array(
          'type' => 'text',
          'label' => t('From'),
          'description' => t('The phone number or client identifier of the party that initiated the call.'),
        ),
        'to' => array(
          'type' => 'text',
          'label' => t('To'),
          'description' => t('The phone number or client identifier of the called party.'),
        ),
        'call_status' => array(
          'type' => 'text',
          'label' => t('Call Status'),
          'description' => t('A descriptive status for the call'),
          'options list' => 'twilio_call_status_options_list',
        ),
        'api_version' => array(
          'type' => 'text',
          'label' => t('API Version'),
          'description' => t('The version of the Twilio API used to handle this call.'),
        ),
        'direction' => array(
          'type' => 'text',
          'label' => t('Direction'),
          'description' => t('A string describing the direction of the call.'),
        ),
        'forwarded_from' => array(
          'type' => 'text',
          'label' => t('Forwarded From'),
          'description' => t('This parameter is set only when Twilio receives a forwarded call, but its value depends on the caller\'s carrier including information when forwarding.'),
        ),
        'caller_name' => array(
          'type' => 'text',
          'label' => t('Caller Name'),
          'description' => t('The caller name from CNAM database.'),
        ),
        'from_city' => array(
            'type' => 'text',
            'label' => t('From City'),
            'description' => t('The city of the caller.'),
        ),
        'from_state' => array(
            'type' => 'text',
            'label' => t('From State'),
            'description' => t('The state or province of the caller.'),
        ),
        'from_zip' => array(
            'type' => 'text',
            'label' => t('From Zip'),
            'description' => t('The postal code of the caller.'),
        ),
        'from_country' => array(
            'type' => 'text',
            'label' => t('From Country'),
            'description' => t('The country of the caller.'),
        ),
        'to_city' => array(
            'type' => 'text',
            'label' => t('To City'),
            'description' => t('The city of the called party.'),
        ),
        'to_state' => array(
            'type' => 'text',
            'label' => t('To State'),
            'description' => t('The state or province of the called party.'),
        ),
        'to_zip' => array(
            'type' => 'text',
            'label' => t('To Zip'),
            'description' => t('The postal code of the called party.'),
        ),
        'to_country' => array(
            'type' => 'text',
            'label' => t('To Country'),
            'description' => t('The country of the called party.'),
        ),
      ),
    ),
    'twilio_gather_request' => $defaults + array(
      'label' => t('Twilio Gather request'),
      'parent' => 'twilio_voice_request',
      'property info' => array(
        'digits' => array(
          'type' => 'text',
          'label' => t('Digits'),
          'description' => t('The digits the caller pressed, excluding the finishOnKey digit if used.'),
        ),
      ),
    ),
    'twilio_record_request' => $defaults + array(
      'label' => t('Twilio Record request'),
      'parent' => 'twilio_voice_request',
      'property info' => array(
        'recording_url' => array(
          'type' => 'uri',
          'label' => t('Recording URL'),
          'description' => t('The URL of the recorded audio.'),
        ),
        'recording_duration' => array(
          'type' => 'integer',
          'label' => t('Recording Duration'),
          'description' => t('The duration of the recorded audio (in seconds).'),
        ),
        'digits' => array(
          'type' => 'text',
          'label' => t('Digits'),
          'description' => t('The key (if any) pressed to end the recording or \'hangup\' if the caller hung up'),
        ),
      ),
    ),
    'twilio_queue_result_request' => $defaults + array(
      'label' => t('Twilio Queue Result request'),
      'parent' => 'twilio_voice_request',
      'property info' => array(
        'queue_result' => array(
          'type' => 'text',
          'label' => t('Queue Result'),
          'description' => t('The final result of the enqueued call.'),
          'options list' => 'twilio_queue_result_options_list',
        ),
        'queue_sid' => array(
          'type' => 'text',
          'label' => t('Queue SID'),
          'description' => t('The SID of the queue.'),
        ),
        'queue_time' => array(
          'type' => 'integer',
          'label' => t('Queue Time'),
          'description' => t('The time the call spent in the queue.'),
        ),
      ),
    ),
    'twilio_queue_wait_request' => $defaults + array(
      'label' => t('Twilio Queue Wait request'),
      'parent' => 'twilio_voice_request',
      'property info' => array(
        'queue_position' => array(
          'type' => 'integer',
          'label' => t('Queue Position'),
          'description' => t('The current queue position for the enqueued call.'),
        ),
        'queue_sid' => array(
          'type' => 'text',
          'label' => t('Queue SID'),
          'description' => t('The SID of the queue.'),
        ),
        'queue_time' => array(
          'type' => 'integer',
          'label' => t('Queue Time'),
          'description' => t('The time the call spent in the queue.'),
        ),
        'avg_queue_time' => array(
          'type' => 'integer',
          'label' => t('Average Queue Time'),
          'description' => t('An average of how long time the current enqueued callers has been in the queue.'),
        ),
        'current_queue_size' => array(
          'type' => 'integer',
          'label' => t('Current Queue Size'),
          'description' => t('The current number of enqueued calls in this queue.'),
        ),
      ),
    ),
    'twilio_call_status_request' => $defaults + array(
      'label' => t('Twilio Call Status request'),
      'parent' => 'twilio_voice_request',
      'property info' => array(
        'call_duration' => array(
          'type' => 'integer',
          'label' => t('Call Duration'),
          'description' => t('The duration in seconds of the just-completed call.'),
        ),
        'recording_url' => array(
          'type' => 'uri',
          'label' => t('Recording URL'),
          'description' => t('The URL of the recorded audio.'),
        ),
        'recording_sid' => array(
          'type' => 'text',
          'label' => t('Recording SID'),
          'description' => t('The unique id of the Recording from this call.'),
        ),
        'recording_duration' => array(
          'type' => 'integer',
          'label' => t('Recording Duration'),
          'description' => t('The duration of the recorded audio (in seconds).'),
        ),
      ),
    ),
    'twilio_dial_call_status_request' => $defaults + array(
      'label' => t('Twilio Dial Call Status request'),
      'parent' => 'twilio_voice_request',
      'property info' => array(
        'dial_call_status' => array(
          'type' => 'text',
          'label' => t('Dial Call Status'),
          'description' => t('The outcome of the <Dial> attempt.'),
        ),
        'dial_call_sid' => array(
          'type' => 'text',
          'label' => t('Dial Call SID'),
          'description' => t('The call sid of the new call leg.'),
        ),
        'dial_call_duration' => array(
          'type' => 'integer',
          'label' => t('Dial Call Duration'),
          'description' => t('The duration in seconds of the dialed call.'),
        ),
        'recording_url' => array(
          'type' => 'uri',
          'label' => t('Recording URL'),
          'description' => t('The URL of the recorded audio.'),
        ),
        'queue_sid' => array(
          'type' => 'text',
          'label' => t('Queue SID'),
          'description' => t('The SID of the queue.'),
        ),
        'dequeue_result' => array(
          'text' => 'text',
          'label' => t('Dequeue Result'),
          'description' => t('One of invalid, bridged, queue-not-found, queue-empty or failed.'),
        ),
        'dequeued_call_sid' => array(
          'type' => 'text',
          'label' => t('Dequeued Call SID'),
          'description' => t('The CallSid of the dequeued call.'),
        ),
        'dequeued_call_queue_time' => array(
          'type' => 'integer',
          'label' => t('Dequeued Call Queue Time'),
          'description' => t('The time the dequeued call spent waiting in the queue.'),
        ),
        'dequeued_call_duration' => array(
          'type' => 'integer',
          'label' => t('Dequeued Call Duration'),
          'description' => t('The time the call was bridged with the dequeued call.'),
        ),
      ),
    ),
    'twilio_sms_status_request' => $defaults + array(
      'label' => t('Twilio SMS Status request'),
      'parent' => 'twilio_voice_request',
      'property info' => array(
        'sms_sid' => array(
          'type' => 'text',
          'label' => t('SMS SID'),
          'description' => t('The SID Twilio has assigned for the SMS message.'),
        ),
        'sms_status' => array(
          'type' => 'text',
          'label' => t('SMS Status'),
          'description' => t('The current status of the SMS message. '),
          'options list' => 'twilio_sms_status_options_list',
        ),
      ),
    ),
    'twilio_twiml_response' => $defaults + array(
      'label' => t('Twiml Response'),
    ),
    'twilio_twiml_dial_response' => $defaults + array(
      'label' => t('Twiml Dial Response'),
      'parent' => 'twilio_twiml_response',
    ),
    'twilio_twiml_gather_response' => $defaults + array(
      'label' => t('Twiml Gather Response'),
      'parent' => 'twilio_twiml_response',
    ),
  );
}

/**
 * Implements hook_event_info().
 */
function twilio_rules_event_info() {
  $defaults = array(
    'group' => t('Twilio'),
    'module' => 'twilio',
  );
  return array(
    'twilio_sms_incoming' => $defaults + array(
      'label' => t('Drupal receives an SMS'),
      'variables' => array(
        'message_request' => array(
          'type' => 'sms',
          'label' => t('Twilio Message Request'),
        ),
        'twiml_response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
    ),
    'twilio_voice_incoming' => $defaults + array(
      'label' => t('Drupal receives a voice call'),
      'variables' => array(
        'voice_request' => array(
          'type' => 'twilio_voice_request',
          'label' => t('Twilio Voice Request'),
        ),
        'twiml_response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function twilio_rules_condition_info() {
  $defaults = array(
    'group' => t('Twilio'),
    'module' => 'twilio',
  );
  return array(
    'twilio_rules_condition_number_belongs_to_user' => $defaults + array(
      'label' => t('Number belongs to a valid user'),
      'arguments' => array(
        'number' => array(
          'type' => 'text',
          'label' => t('Phone Number'),
        ),
      ),
    ),
    'twilio_rules_condition_user_has_verified_number' => $defaults + array(
      'label' => t('User has a verified number'),
      'arguments' => array(
        'account' => array(
          'type' => 'user',
          'label' => t('User'),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_action_info().
 */
function twilio_rules_action_info() {
  $defaults = array(
    'group' => t('Twilio'),
    'module' => 'twilio',
    'named parameter' => TRUE,
  );
  return array(
    'twilio_send_sms_to_user' => $defaults + array(
      'label' => t('Send an SMS to a user'),
      'base' => 'twilio_rules_action_send_sms_to_user',
      'parameter' => array(
        'account' => array(
          'type' => 'user',
          'label' => t('User'),
          'save' => TRUE,
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
        ),
        'media' => array(
          'type' => 'text',
          'optional' => TRUE,
          'label' => t('Media path'),
        ),
      ),
    ),
    'twilio_send_sms_to_all_users' => $defaults + array(
      'label' => t('Send an SMS to all users'),
      'base' => 'twilio_rules_action_send_sms_to_all_users',
      'parameter' => array(
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
        ),
        'media' => array(
          'type' => 'text',
          'optional' => TRUE,
          'label' => t('Media path'),
        ),
      ),
    ),
    'twilio_send_sms_to_number' => $defaults + array(
      'label' => t('Send an SMS to a number'),
      'base' => 'twilio_rules_action_send_sms_to_number',
      'parameter' => array(
        'country' => array(
          'type' => 'text',
          'label' => t('Country code'),
          'options list' => 'twilio_country_codes',
        ),
        'number' => array(
          'type' => 'text',
          'label' => t('Number'),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
        ),
        'media' => array(
          'type' => 'text',
          'optional' => TRUE,
          'label' => t('Media path'),
        ),
      ),
    ),
    'twilio_create_call' => $defaults + array(
      'label' => t('Create Call'),
      'base' => 'twilio_rules_create_call',
      'parameter' => array(
        'from' => array(
          'type' => 'text',
          'label' => t('From'),
          'description' => t('The phone number or client identifier to use as the caller id.'),
        ),
        'to' => array(
          'type' => 'text',
          'label' => t('To'),
          'description' => t('The phone number, SIP address or client identifier to call.'),
        ),
        'url' => array(
          'type' => 'uri',
          'label' => t('URL'),
          'description' => t('The fully qualified URL that should be consulted when the call connects.'),
        ),
        //'application_sid',
        'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'description' => t('This tells Twilio whether to request the URL via HTTP GET or POST.'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        //'fallback_url',
        //'fallback_method',
        'status_callback' => array(
          'type' => 'uri',
          'label' => t('Status Callback'),
          'description' => t('This attribute allows you to specify a URL for Twilio to send webhook requests to on each event specified in the statusCallbackEvent attribute.'),
          'optional' => TRUE,
        ),
        'status_callback_method' => array(
          'type' => 'text',
          'label' => t('Status Callback Method'),
          'description' => t('This attribute allows you to specify which HTTP method Twilio should use when requesting the URL in the statusCallback attribute.'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'status_callback_event' => array(
          'type' => 'list<text>',
          'label' => t('Status Callback Event'),
          'description' => t('This attribute allows you to specify which events Twilio should webhook on.'),
          'options list' => 'twilio_status_callback_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'send_digits' => array(
          'type' => 'text',
          'label' => ('Send Digits'),
          'optional' => TRUE,
        ),
        'timeout' => array(
          'type' => 'integer',
          'label' => ('Timeout'),
          'optional' => TRUE,
        ),
        'record' => array(
          'type' => 'boolean',
          'label' => t('Record'),
          'optional' => TRUE,
        ),
      ),
      'provides' => array(
        'call_instance' => array(
          'type' => 'twilio_call_instance',
          'label' => t('Call Instance'),
        ),
      ),
    ),
    'twilio_send_message' => $defaults + array(
      'label' => t('Send Message'),
      'base' => 'twilio_rules_send_message',
      'parameter' => array(
        'to' => array(
          'type' => 'text',
          'label' => t('To'),
          'description' => t('The destination phone number.'),
        ),
        'from' => array(
          'type' => 'text',
          'label' => t('From'),
          'description' => t('A Twilio phone number or alphanumeric sender ID enabled for the type of message you wish to send.'),
        ),
        //'messaging_service_sid',
        'body' => array(
          'type' => 'text',
          'label' => t('Body'),
          'description' => t('The text of the message you want to send, limited to 1600 characters.'),
        ),
        'media_url' => array(
          'type' => 'uri',
          'label' => t('Media Url'),
          'description' => t('The URL of the media you wish to send out with the message. gif , png and jpeg content is currently supported and will be formatted correctly on the recipient\'s device.'),
        ),
        'status_callback' => array(
          'type' => 'uri',
          'label' => t('Status Callback'),
          'description' => t('This attribute allows you to specify a URL for Twilio to send webhook requests to on each event specified in the statusCallbackEvent attribute.'),
          'optional' => TRUE,
        ),
        //'application_sid',
        'max_price' => array(
          'type' => 'decimal',
          'label' => t('Max Price'),
          'description' => t('The total maximum price in US dollars acceptable for the message to be delivered.'),
        )
      ),
      'provides' => array(
        'message_instance' => array(
          'type' => 'twilio_message_instance',
          'label' => t('Message Instance'),
        ),
      ),
    ),
    'twilio_load_rule_component' => $defaults + array(
      'label' => t('Load Twilio Rule Component'),
      'base' => 'twilio_rules_load_rule_component',
      'parameter' => array(
        'rule_component' => array(
          'type' => 'text',
          'label' => t('Rule Component'),
          'options list' => 'twilio_rules_component_options_list',
        ),
      ),
      'provides' => array(
        'twilio_component_uri' => array(
          'type' => 'uri',
          'label' => t('Twilio Component URI'),
        ),
      ),
    ),
    'twilio_twiml_dial' => $defaults + array(
      'label' => t('Twiml Verb: Dial'),
      'base' => 'twilio_rules_twiml_dial',
      'parameter' => array(
        'action' => array(
          'type' => 'uri',
          'label' => t('Action'),
          'description' => t('When the dialed call ends, Twilio will make a GET or POST request to this URL.'),
          'optional' => TRUE,
        ),
        'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'description' => t('This tells Twilio whether to request the \'action\' URL via HTTP GET or POST.'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'timeout' => array(
          'type' => 'integer',
          'label' => t('Timeout'),
          'description' => t('This attribute sets the limit in seconds that Twilio waits for the called party to answer the call.'),
          'optional' => TRUE,
        ),
        'hangup_on_star' => array(
          'type' => 'boolean',
          'label' => t('Hangup on Star'),
          'description' => t('This attribute lets the calling party hang up on the called party by pressing the \'*\' key on his phone.'),
          'optional' => TRUE,
        ),
        'time_limit' => array(
          'type' => 'integer',
          'label' => t('Time Limit'),
          'description' => t('This attribute sets the maximum duration of the call in seconds.'),
          'optional' => TRUE,
        ),
        'caller_id' => array(
          'type' => 'text',
          'label' => t('Caller ID'),
          'description' => t('This attribute lets you specify the caller ID that will appear to the called party when Twilio calls.'),
          'optional' => TRUE,
        ),
        'record' => array(
          'type' => 'text',
          'label' => t('Record'),
          'description' => t('This attribute lets you record both legs of a call within the associated Dial verb.'),
          'options list' => 'twilio_record_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'trim' => array(
          'type' => 'boolean',
          'label' => t('Trim'),
          'description' => t('This attribute lets you specify whether to trim leading and trailing silence from your audio files.'),
          'optional' => TRUE,
        ),
        'response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
      'provides' => array(
        'dial_response' => array(
          'type' => 'twilio_twiml_dial_response',
          'label' => t('Dial Response'),
        )
      ),
    ),
    'twilio_twiml_client' => $defaults + array(
      'label' => t('Twiml Noun: Client'),
      'base' => 'twilio_rules_twiml_client',
      'parameter' => array(
        'url' => array(
          'type' => 'uri',
          'label' => t('URL'),
          'description' => t('This attribute allows you to specify a url for a TwiML document that will run on the called party\'s end, after she answers, but before the parties are connected.'),
          'optional' => TRUE,
        ),
        'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'description' => t('This attribute allows you to specify which HTTP method Twilio should use when requesting the URL in the \'url\' attribute.'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'status_callback_event' => array(
          'type' => 'list<text>',
          'label' => t('Status Callback Event'),
          'description' => t('This attribute allows you to specify which events Twilio should webhook on.'),
          'options list' => 'twilio_status_callback_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'status_callback' => array(
          'type' => 'uri',
          'label' => t('Status Callback'),
          'description' => t('This attribute allows you to specify a URL for Twilio to send webhook requests to on each event specified in the statusCallbackEvent attribute.'),
          'optional' => TRUE,
        ),
        'status_callback_method' => array(
          'type' => 'text',
          'label' => t('Status Callback Method'),
          'description' => t('This attribute allows you to specify which HTTP method Twilio should use when requesting the URL in the statusCallback attribute.'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'client_id' => array(
          'type' => 'text',
          'label' => t('Client ID'),
          'description' => t('The client identifier currently may only contain alpha-numeric and underscore characters.'),
        ),
        'response' => array(
          'type' => 'twilio_twiml_dial_response',
          'label' => t('Twiml Dial Response'),
        ),
      ),
    ),
    'twilio_twiml_conference' => $defaults + array(
      'label' => t('Twiml Noun: Conference'),
      'base' => 'twilio_rules_twiml_conference',
      'parameter' => array(
        'muted' => array(
          'type' => 'boolean',
          'label' => t('Muted'),
          'description' => t('This attribute lets you specify whether a participant can speak on the conference.'),
          'optional' => TRUE,
        ),
        'beep' => array(
          'type' => 'boolean',
          'label' => t('Beep'),
          'description' => t('This attribute lets you specify whether a notification beep is played to the conference when a participant joins or leaves the conference.'),
          'optional' => TRUE,
        ),
        'start_conference_on_enter' => array(
          'type' => 'boolean',
          'label' => t('Start Conference On Enter'),
          'description' => t('This attribute tells a conference to start when this participant joins the conference, if it is not already started.'),
          'optional' => TRUE,
        ),
        'end_conference_on_exit' => array(
          'type' => 'boolean',
          'label' => t('End Conference On Exit'),
          'description' => t('If a participant has this attribute set to true, then when that participant leaves, the conference ends and all other participants drop out.'),
          'optional' => TRUE,
        ),
        'wait_url' => array(
          'type' => 'uri',
          'label' => t('Wait Url'),
          'description' => t('This attribute lets you specify a URL for music that plays before the conference has started.'),
          'optional' => TRUE,
        ),
        'wait_method' => array(
          'type' => 'text',
          'label' => t('Wait Method'),
          'description' => t('This attribute indicates which HTTP method to use when requesting \'waitUrl\'.'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'max_participants' => array(
          'type' => 'integer',
          'label' => t('Max Participants'),
          'description' => t('This attribute indicates the maximum number of participants you want to allow within a named conference room.'),
          'optional' => TRUE,
        ),
        'record' => array(
          'type' => 'text',
          'label' => t('Record'),
          'description' => t('This attribute lets you record an entire conference.'),
          'options list' => 'twilio_record_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'trim' => array(
          'type' => 'boolean',
          'label' => t('Trim'),
          'description' => t('This attribute lets you specify whether to trim leading and trailing silence from your audio files.'),
          'optional' => TRUE,
        ),
        'status_callback_event' => array(
          'type' => 'list<text>',
          'label' => t('Status Callback Event'),
          'options list' => 'twilio_status_callback_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'status_callback' => array(
          'type' => 'uri',
          'label' => t('Status Callback'),
          'optional' => TRUE,
        ),
        'status_callback_method' => array(
          'type' => 'text',
          'label' => t('Status Callback Method'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'event_callback_url' => array(
          'type' => 'uri',
          'label' => t('Event Callback URL'),
          'optional' => TRUE,
        ),
        'conference_name' => array(
          'type' => 'text',
          'label' => t('Conference Name'),
        ),
        'response' => array(
          'type' => 'twilio_twiml_dial_response',
          'label' => t('Twiml Dial Response'),
        ),
      ),
    ),
    'twilio_twiml_number' => $defaults + array(
      'label' => t('Twiml Noun: Number'),
      'base' => 'twilio_rules_twiml_number',
      'parameter' => array(
        'send_digits' => array(
          'type' => 'text',
          'label' => t('Send Digits'),
        ),
        'url' => array(
          'type' => 'uri',
          'label' => t('URL'),
          'optional' => TRUE,
        ),
        'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'status_callback_event' => array(
          'type' => 'list<text>',
          'label' => t('Status Callback Event'),
          'options list' => 'twilio_status_callback_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'status_callback' => array(
          'type' => 'uri',
          'label' => t('Status Callback'),
          'optional' => TRUE,
        ),
        'status_callback_method' => array(
          'type' => 'text',
          'label' => t('Status Callback Method'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'number' => array(
          'type' => 'text',
          'label' => t('Number'),
        ),
        'response' => array(
          'type' => 'twilio_twiml_dial_response',
          'label' => t('Twiml Dial Response'),
        ),
      ),
    ),
    'twilio_twiml_queue' => $defaults + array(
      'label' => t('Twiml Noun: Queue'),
      'base' => 'twilio_rules_twiml_queue',
      'parameter' => array(
        'url' => array(
          'type' => 'uri',
          'label' => t('URL'),
          'optional' => TRUE,
        ),
        'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'reservation_sid' => array(
          'type' => 'text',
          'label' => t('Reservation SID'),
          'optional' => TRUE,
        ),
        'post_work_activity_sid' => array(
          'type' => 'text',
          'label' => t('Post Work Activity SID'),
          'optional' => TRUE,
        ),
        'queue_name' => array(
          'type' => 'text',
          'label' => t('Queue Name'),
        ),
        'response' => array(
          'type' => 'twilio_twiml_dial_response',
          'label' => t('Twiml Dial Response'),
        ),
      ),
    ),
    'twilio_twiml_sip' => $defaults + array(
      'label' => t('Twiml Noun: Sip'),
      'base' => 'twilio_rules_twiml_sip',
      'parameter' => array(
        'url' => array(
          'type' => 'uri',
          'label' => t('URL'),
          'optional' => TRUE,
        ),
        'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'status_callback_event' => array(
          'type' => 'list<text>',
          'label' => t('Status Callback Event'),
          'options list' => 'twilio_status_callback_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'status_callback' => array(
          'type' => 'uri',
          'label' => t('Status Callback'),
          'optional' => TRUE,
        ),
        'status_callback_method' => array(
          'type' => 'text',
          'label' => t('Status Callback Method'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'address' => array(
          'type' => 'text',
          'label' => t('Address'),
        ),
        'response' => array(
          'type' => 'twilio_twiml_dial_response',
          'label' => t('Twiml Dial Response'),
        ),
      ),
    ),
    'twilio_twiml_enqueue' => $defaults + array(
      'label' => t('Twiml Verb: Enqueue'),
      'base' => 'twilio_rules_twiml_enqueue',
      'parameter' => array(
        'action' => array(
          'type' => 'uri',
          'label' => t('Action'),
        ),
        'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'wait_url' => array(
          'type' => 'uri',
          'label' => t('WaitUrl'),
          'optional' => TRUE,
        ),
        'wait_url_method' => array(
          'type' => 'text',
          'label' => t('WaitUrlMethod'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'workflow_sid' => array(
          'type' => 'text',
          'label' => t('workflowSid'),
          'optional' => TRUE,
        ),
        'queue_name' => array(
          'type' => 'text',
          'label' => t('Queue Name'),
        ),
        'response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
    ),
    'twilio_twiml_gather' => $defaults + array(
      'label' => t('Twiml Verb: Gather'),
      'base' => 'twilio_rules_twiml_gather',
      'parameter' => array(
        'action' => array(
          'type' => 'uri',
          'label' => t('Action'),
        ),
        'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'timeout' => array(
          'type' => 'integer',
          'label' => t('Timeout'),
          'optional' => TRUE,
        ),
        'finish_on_key' => array(
          'type' => 'text',
          'label' => t('Finish on Key'),
          'optional' => TRUE,
        ),
        'num_digits' => array(
          'type' => 'integer',
          'label' => t('Number of Digits'),
          'optional' => TRUE,
        ),
        'response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
      'provides' => array(
        'gather_response' => array(
          'type' => 'twilio_twiml_gather_response',
          'label' => t('Gather Response'),
        ),
      ),
    ),
    'twilio_twiml_hangup' => $defaults + array(
      'label' => t('Twiml Verb: Hangup'),
      'base' => 'twilio_rules_twiml_hangup',
      'parameter' => array(
        'response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
    ),
    'twilio_twiml_leave' => $defaults + array(
      'label' => t('Twiml Verb: Leave'),
      'base' => 'twilio_rules_twiml_leave',
      'parameter' => array(
        'response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
    ),
    'twilio_twiml_pause' => $defaults + array(
      'label' => t('Twiml Verb: Pause'),
      'base' => 'twilio_rules_twiml_pause',
      'parameter' => array(
        'length' => array(
          'type' => 'integer',
          'label' => t('Length'),
        ),
        'response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
    ),
    'twilio_twiml_play' => $defaults + array(
      'label' => t('Twiml Verb: Play'),
      'base' => 'twilio_rules_twiml_play',
      'parameter' => array(
        'loop' => array(
          'type' => 'integer',
          'label' => t('Loop'),
          'optional' => TRUE,
        ),
        'digits' => array(
          'type' => 'text',
          'label' => t('Digits'),
          'optional' => TRUE,
        ),
        'url' => array(
          'type' => 'uri',
          'label' => t('URL'),
        ),
        'response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
    ),
    'twilio_twiml_record' => $defaults + array(
      'label' => t('Twiml Verb: Record'),
      'base' => 'twilio_rules_twiml_record',
      'parameter' => array(
        'action' => array(
          'type' => 'uri',
          'label' => t('Action'),
        ),
        'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'timeout' => array(
          'type' => 'integer',
          'label' => t('Timeout'),
          'optional' => TRUE,
        ),
        'finish_on_key' => array(
          'type' => 'text',
          'label' => t('Finish on Key'),
          'optional' => TRUE,
        ),
        'max_length' => array(
          'type' => 'integer',
          'label' => t('Maximum Length'),
          'optional' => TRUE,
        ),
        'transcribe' => array(
          'type' => 'boolean',
          'label' => t('Transcribe'),
          'optional' => TRUE,
        ),
        'transcribe_callback' => array(
          'type' => 'uri',
          'label' => t('Transcribe Callback'),
          'optional' => TRUE,
        ),
        'play_beep' => array(
          'type' => 'boolean',
          'label' => t('Play Beep'),
          'optional' => TRUE,
        ),
        'trim' => array(
          'type' => 'boolean',
          'label' => t('Trim'),
          'optional' => TRUE,
        ),
        'response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
    ),
    'twilio_twiml_redirect' => $defaults + array(
      'label' => t('Twiml Verb: Redirect'),
      'base' => 'twilio_rules_twiml_enqueue',
      'parameter' => array(
        'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'destination' => array(
          'type' => 'uri',
          'label' => t('Destination'),
        ),
        'response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
    ),
    'twilio_twiml_reject' => $defaults + array(
      'label' => t('Twiml Verb: Reject'),
      'base' => 'twilio_rules_twiml_reject',
      'parameter' => array(
        'reason' => array(
          'type' => 'text',
          'label' => t('Reason'),
          'options list' => 'twilio_reason_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
    ),
    'twilio_twiml_say' => $defaults + array(
      'label' => t('Twiml Verb: Say'),
      'base' => 'twilio_rules_twiml_say',
      'parameter' => array(
        'voice' => array(
          'type' => 'text',
          'label' => t('Voice'),
          'options list' => 'twilio_voice_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'loop' => array(
          'type' => 'integer',
          'label' => t('Loop'),
          'optional' => TRUE,
        ),
        'language' => array(
          'type' => 'text',
          'label' => t('Language'),
          'options list' => 'twilio_language_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'text' => array(
          'type' => 'text',
          'label' => t('Text'),
        ),
        'response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
    ),
    'twilio_twiml_sms' => $defaults + array(
      'label' => t('Twiml Verb: SMS'),
      'base' => 'twilio_rules_twiml_sms',
      'parameter' => array(
        'to' => array(
          'type' => 'text',
          'label' => t('To'),
        ),
        'from' => array(
          'type' => 'text',
          'label' => t('From'),
        ),
        'action' => array(
          'type' => 'uri',
          'label' => t('Action'),
          'optional' => TRUE,
        ),
        'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'options list' => 'twilio_method_options_list',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
        'status_callback' => array(
          'type' => 'uri',
          'label' => t('Status Callback'),
          'optional' => TRUE,
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
        ),
        'response' => array(
          'type' => 'twilio_twiml_response',
          'label' => t('Twiml Response'),
        ),
      ),
    ),
  );
}

/**
 * Action: Send an SMS to a user.
 */
function twilio_rules_action_send_sms_to_user($account, $message, $media) {
  if (!empty($account->twilio_user['number']) && $account->twilio_user['status'] == 2) {
    twilio_send($account->twilio_user['number'], $message, $account->twilio_user['country'], $media);
  }
}

/**
 * Action: Send an SMS to all users.
 */
function twilio_rules_action_send_sms_to_all_users($message, $media) {
  // Fetch all site users with confirmed numbers.
  $results = db_select('twilio_user', 't')
    ->fields('t')
    ->condition('t.status', TWILIO_USER_CONFIRMED)
    ->execute()
    ->fetchAll();
  // If we have results, iterate through and send the message.
  if (!empty($results)) {
    foreach ($results as $result) {
      twilio_send($result->number, $message, $result->country, $media);
    }
  }
}

/**
 * Action: Send an SMS to a number.
 */
function twilio_rules_action_send_sms_to_number($country, $number, $message, $media) {
  twilio_send($number, $message, $country, $media);
}

function twilio_rules_create_call($parameters) {
  return twilio_call($parameters);
}

function twilio_rules_load_rule_component($parameters) {
  return array('twilio_component_uri' => url('twilio/voice/' . $parameters['rule_component'], array('absolute' => TRUE)));
}

function twilio_rules_twiml_dial($parameters) {
  $options = _twilio_map_options($parameters, array(
    'action' => 'action',
    'method' => 'method',
    'timeout' => 'timeout',
    'hangupOnStar' => 'hangup_on_star',
    'timeLimit' => 'time_limit',
    'callerId' => 'callerId',
    'record' => 'record',
    'trim' => 'trim',
  ));
  $dial_response = $parameters['response']->dial(NULL, $options);

  return array('dial_response' => $dial_response);
}

function twilio_rules_twiml_client($parameters) {
  $options = _twilio_map_options($parameters, array(
    'url' => 'url',
    'method' => 'method',
    'statusCallbackEvent' => 'status_callback_event',
    'statusCallback' => 'status_callback',
    'statusCallbackMethod' => 'status_callback_method',
  ));
  $parameters['response']->client($parameters['client_id'], $options);
}

function twilio_rules_twiml_conference($parameters) {
  $options = _twilio_map_options($parameters, array(
    'muted' => 'muted',
    'beep' => 'beep',
    'startConferenceOnEnter' => 'start_conference_on_enter',
    'endConferenceOnExit' => 'end_conference_on_exit',
    'waitUrl' => 'wait_url',
    'waitMethod' => 'wait_method',
    'maxParticipants' => 'max_participants',
    'record' => 'record',
    'trim' => 'trim',
    'statusCallbackEvent' => 'status_callback_event',
    'statusCallback' => 'status_callback',
    'statusCallbackMethod' => 'status_callback_method',
    'eventCallbackUrl' => 'event_callback_url',
  ));
  $parameters['response']->conference($parameters['conference_name'], $options);
}

function twilio_rules_twiml_number($parameters) {
  $options = _twilio_map_options($parameters, array(
    'sendDigits' => 'send_digits',
    'url' => 'url',
    'method' => 'method',
    'statusCallbackEvent' => 'status_callback_event',
    'statusCallback' => 'status_callback',
    'statusCallbackMethod' => 'status_callback_method',
  ));
  $parameters['response']->number($parameters['number'], $options);
}

function twilio_rules_twiml_queue($parameters) {
  $options = _twilio_map_options($parameters, array(
    'url' => 'url',
    'method' => 'method',
    'reservationSid' => 'reservation_sid',
    'postWorkActivitySid' => 'post_work_activity_sid',
  ));
  $parameters['response']->queue($parameters['queue_name'], $options);
}

function twilio_rules_twiml_sip($parameters) {
  $options = _twilio_map_options($parameters, array(
    'url' => 'url',
    'method' => 'method',
    'statusCallbackEvent' => 'status_callback_event',
    'statusCallback' => 'status_callback',
    'statusCallbackMethod' => 'status_callback_method',
  ));
  $parameters['response']->sip($parameters['address'], $options);
}

function twilio_rules_twiml_enqueue($parameters) {
  $options = _twilio_map_options($parameters, array(
    'action' => 'action',
    'method' => 'method',
    'waitUrl' => 'wait_url',
    'waitUrlMethod' => 'wait_url_method',
    'workflowSid' => 'workflow_sid',
  ));
  $parameters['response']->enqueue($parameters['queue_name'], $options);
}

function twilio_rules_twiml_gather($parameters) {
  $options = _twilio_map_options($parameters, array(
    'action' => 'action',
    'method' => 'method',
    'timeout' => 'timeout',
    'finishOnKey' => 'finish_on_key',
    'numDigits' => 'num_digits',
  ));
  $gather_response = $parameters['response']->gather($options);

  return array('gather_response' => $gather_response);
}

function twilio_rules_twiml_hangup($parameters) {
  $parameters['response']->hangup();
}

function twilio_rules_twiml_leave($parameters) {
  $parameters['response']->leave();
}

function twilio_rules_twiml_pause($parameters) {
  $options = _twilio_map_options($parameters, array(
    'length' => 'length',
  ));
  $parameters['response']->pause($options);
}

function twilio_rules_twiml_play($parameters) {
  $options = _twilio_map_options($parameters, array(
    'loop' => 'loop',
    'digits' => 'digits',
  ));
  $parameters['response']->play($parameters['url'], $options);
}

function twilio_rules_twiml_record($parameters) {
  $options = _twilio_map_options($parameters, array(
    'action' => 'action',
    'method' => 'method',
    'timeout' => 'timeout',
    'finishOnKey' => 'finish_on_key',
    'maxLength' => 'max_length',
    'transcribe' => 'transcribe',
    'transcribeCallback' => 'transcribe_callback',
    'playBeep' => 'play_beep',
    'trim' => 'trim',
  ));
  $parameters['response']->record($options);
}

function twilio_rules_twiml_redirect($parameters) {
  $options = _twilio_map_options($parameters, array(
    'method' => 'method',
  ));
  $parameters['response']->redirect($parameters['destination'], $options);
}

function twilio_rules_twiml_reject($parameters) {
  $options = _twilio_map_options($parameters, array(
    'reason' => 'reason',
  ));
  $parameters['response']->reject($options);
}

function twilio_rules_twiml_say($parameters) {
  $options = _twilio_map_options($parameters, array(
    'voice' => 'voice',
    'loop' => 'loop',
    'language' => 'language',
  ));
  $parameters['response']->say($parameters['text'], $options);
}

function twilio_rules_twiml_sms($parameters) {
  $options = _twilio_map_options($parameters, array(
    'to' => 'to',
    'from' => 'from',
    'action' => 'action',
    'method' => 'method',
    'statusCallback' => 'status_callback',
  ));
  $parameters['response']->sms($parameters['message'], $options);
}

/**
 * Condition: Validate if a number belongs to a user on the site.
 */
function twilio_rules_condition_number_belongs_to_user($number) {
  return twilio_verify_number($number);
}

/**
 * Condition: Validate if the user has a verified number.
 */
function twilio_rules_condition_user_has_verified_number($user) {
  // Check if the user has TWILIO_USER_CONFIRMED status.
  if (!empty($user->twilio_user) && $user->twilio_user['status'] == TWILIO_USER_CONFIRMED) {
    return TRUE;
  }
  return FALSE;
}
