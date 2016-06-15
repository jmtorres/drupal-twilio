<?php

function twilio_status_callback_options_list() {
  return array(
    'initiated' => t('Initiated'),
    'ringing' => t('Ringing'),
    'answered' => t('Answered'),
    'completed' => t('Completed'),
  );
}

function twilio_reason_options_list() {
  return array(
    'rejected' => t('Rejected'),
    'busy' => t('Busy'),
  );
}

function twilio_method_options_list() {
  return array(
    'GET' => 'GET',
    'POST' => 'POST',
  );
}

function twilio_voice_options_list() {
  return array(
    'man' => t('Man'),
    'woman' => t('Woman'),
    'alice' => t('Alice'),
  );
}

function twilio_language_options_list() {
  return array(
    'da-DK' => t('Danish, Denmark'),
    'de-DE' => t('German, Germany'),
    'en-AU' => t('English, Australia'),
    'en-CA' => t('English, Canada'),
    'en-GB' => t('English, UK'),
    'en-IN' => t('English, India'),
    'en-US' => t('English, United States'),
    'ca-ES' => t('Catalan, Spain'),
    'es-ES' => t('Spanish, Spain'),
    'es-MX' => t('Spanish, Mexico'),
    'fi-FI' => t('Finnish, Finland'),
    'fr-CA' => t('French, Canada'),
    'fr-FR' => t('French, France'),
    'it-IT' => t('Italian, Italy'),
    'ja-JP' => t('Japanese, Japan'),
    'ko-KR' => t('Korean, Korea'),
    'nb-NO' => t('Norwegian, Norway'),
    'nl-NL' => t('Dutch, Netherlands'),
    'pl-PL' => t('Polish-Poland'),
    'pt-BR' => t('Portuguese, Brazil'),
    'pt-PT' => t('Portuguese, Portugal'),
    'ru-RU' => t('Russian, Russia'),
    'sv-SE' => t('Swedish, Sweden'),
    'zh-CN' => t('Chinese (Mandarin)'),
    'zh-HK' => t('Chinese (Cantonese)'),
    'zh-TW' => t('Chinese (Taiwanese Mandarin)'),
  );
}

function twilio_record_options_list() {
  return array(
    'do-not-record' => t('Do not record'),
    'record-from-answer' => t('Record from answer'),
    'record-from-ringing' => t('Record from ringing'),
    'record-from-answer-dual' => t('Record from answer (Dual Channel)'),
    'record-from-ringing-dual' => t('Record from ringing (Dual Channel)'),
  );
}

function twilio_call_status_options_list() {
  return array(
    'queued' => t('Queued'),           //The call is ready and waiting in line before going out.
    'ringing' => t('Ringing'),         //The call is currently ringing.
    'in-progress' => t('In Progress'), //The call was answered and is currently in progress.
    'completed' => t('Completed'),     //The call was answered and has ended normally.
    'busy' => t('Busy'),               //The caller received a busy signal.
    'failed' => t('Failed'),           //The call could not be completed as dialed, most likely because the phone number was non-existent.
    'no-answer' => t('No Answer'),     //The call ended without being answered.
    'canceled' => t('Canceled'),       //The call was canceled via the REST API while queued or ringing.
  );
}

function twilio_dial_call_status_options_list() {
  return array(
    'completed' => t('Completed'), //The called party answered the call and was connected to the caller.
    'answered' => t('Answered'), //The called party answered the call and was connected to the caller, returned when dialing a conference.
    'busy' => t('Busy'), //Twilio received a busy signal when trying to connect to the called party.
    'no-answer' => t('No Answer'), //The called party did not pick up before the timeout period passed.
    'failed' => t('Failed'), //Twilio was unable to route to the given phone number. This is frequently caused by dialing a properly formatted but non-existent phone number.
    'canceled' => t('Canceled'), //The call was canceled via the REST API before it was answered.
  );
}

function twilio_sms_status_options_list() {
  return array(
    'sending' => t('Sending'),
    'sent' => t('Sent'),
    'invalid' => t('Invalid'),
    'failed' => t('Failed'),
  );
}

function twilio_queue_result_options_list() {
  return array(
    'bridged' => t('Bridged'), //The call was dequeued and bridged to the dequeuer.
    'bridging-in-process' => t('Bridging In Process'), //Twilio has been instructed to bridge the enqueued party.
    'error' => t('Error'), //The TwiML contained an error, either in the <Enqueue> verb itself or in the TwiML retrieved from a waitUrl. Check the App Monitor.
    'hangup' => t('Hangup'), //The enqueued caller hung up before connecting to a dequeued call.
    'leave' => t('Leave'), //The enqueued caller exited the queue via the <Leave> verb.
    'redirected' => t('Redirected'), //While in the queue, the call was redirected out of the queue, typically by a REST API request.
    'redirected-from-bridged' => t('Redirected From Bridged'), //The queued and then successfully bridged session was transferred out.
    'queue-full' => t('Queue Full'), //The targeted queue was full, thus the enqueue attempt was rejected.
    'system-error' => t('System Error'), //The Twilio system malfunctioned during the enqueue process.
  );
}

function twilio_rules_component_options_list() {
  return rules_get_components(TRUE, 'action');
}