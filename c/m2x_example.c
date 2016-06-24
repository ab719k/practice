/* m2x */

#include <stdio.h>

#include "m2x.h"
#include "device.h"

#include "stdlib.h"

#define MAX_NUM_ENTRIES 25

const char *M2X_KEY = "d0dd4116c51ae802afe8aab0dd79c718";
const char *name = "sensor_d2_via_app";
const char *description = "Put Random Value";
const char *tags = "RandVal";
const char *visibility = "private";

const char *stream_name = "RandomValue";
const char *stream_name_2 = "RandValue_less50";

/* An App to create a new device and stream then update the stream with random values */
int main()
{
  /* Data Structure */
  m2x_context *ctx = NULL;
  char buf[2048];
  m2x_response response;
  const char device_id[33];
  int randValue, randValue_2, i;

/* 1. Create a Device */

  /* 1.1 Open the Account using Master Key. */
  ctx = m2x_open(M2X_KEY);

  /* 1.2 Enable Verbose */
  m2x_set_verbose(ctx, 1);

  /* 1.3 Create a Device */
  sprintf(buf, "{\"name\": \"%s\", \"description\": \"%s\", \"tags\": \"%s\", \"visibility\": \"%s\"}",
          name, description, tags, visibility);
  printf("Create device: %s\n", buf);
  response = m2x_device_create(ctx, buf);
  printf("Status code: %d\n", response.status);
  if (m2x_is_success(&response) && response.raw) {
    printf("%s\n", response.raw);
    printf("Feed ID    : %s\n", json_object_get_string(json_value_get_object(
        response.json), "id"));

    memcpy(device_id, json_object_get_string(json_value_get_object(response.json), "id"),
                sizeof(device_id));
    printf("%s\n", &device_id);
  }

  /* Release the response so that same struct is used for next response */
  m2x_release_response(&response);
  /* Sleep for about a min, since it takes ~40 sec to create the device */
  sleep(45);

/* 2. Cretae a Stream */
  memset(&buf, 0, sizeof(buf));
  sprintf(buf, "{ \"unit\": { \"label\": \"celsius\", \"symbol\": \"C\" }, \"type\": \"numeric\" }");
  printf("\nBefore m2x_device_stream_create device_id: %s", &device_id);
  printf("\nBefore m2x_device_stream_create stream_name: %s", stream_name);
  response = m2x_device_stream_create(ctx, &device_id, stream_name, buf);
  if (m2x_is_success(&response) && response.raw) {
    printf("%s\n", response.raw);
  }
  /* Release the response so that same struct is used for next response */
  m2x_release_response(&response);
  /* Sleep for about a min, since it takes ~40 sec to create the device */
  sleep(30);

/* 2. Cretae a 2nd Stream */
  memset(&buf, 0, sizeof(buf));
  sprintf(buf, "{ \"unit\": { \"label\": \"celsius\", \"symbol\": \"C\" }, \"type\": \"numeric\" }");
  printf("\nBefore m2x_device_stream_create device_id: %s", &device_id);
  printf("\nBefore m2x_device_stream_create stream_name: %s", stream_name_2);
  response = m2x_device_stream_create(ctx, &device_id, stream_name_2, buf);
  if (m2x_is_success(&response) && response.raw) {
    printf("%s\n", response.raw);
  }
  /* Release the response so that same struct is used for next response */
  m2x_release_response(&response);
  /* Sleep for about a min, since it takes ~40 sec to create the device */
  sleep(30);


/* 3.0 Create a Trigger */
  memset(&buf, 0, sizeof(buf));
  sprintf(buf, "{\"stream\": \"%s\", \"name\": \"High Temperature\", \"condition\": \">\", \"value\": \"75\", \"callback_url\": \"http://requestb.in/1dsaa5u1\", \"status\": \"enabled\",  \"send_location\": \"true\"  }",
          stream_name);
  response = m2x_device_trigger_create(ctx, &device_id, buf);
    if (m2x_is_success(&response) && response.raw) {
      printf("%s\n", response.raw);
    }
  sleep(5);

/* 3. Generate Random Values */
  for( i = 0; i < MAX_NUM_ENTRIES; i++ )
  {
    randValue = rand() % 100;
    randValue_2 = rand() % 50;
    printf("Value to be updated is %d &  %d @%dth position \n", randValue, randValue_2, i+1);

/* 4. update the Random values to the 1st stream */
    memset(&buf, 0, sizeof(buf));
    sprintf(buf, "{ \"value\": \"%d\" }", randValue);
    response = m2x_device_stream_value_update(ctx, &device_id, stream_name, buf);
    if (m2x_is_success(&response) && response.raw) {
      printf("%s\n", response.raw);
    }
    sleep(5);

/* 4. update the Random values to the 2nd stream */
    memset(&buf, 0, sizeof(buf));
    sprintf(buf, "{ \"value\": \"%d\" }", randValue_2);
    response = m2x_device_stream_value_update(ctx, &device_id, stream_name_2, buf);
    if (m2x_is_success(&response) && response.raw) {
      printf("%s\n", response.raw);
    }
    sleep(5);

  }
  /* Release the response so that same struct is used for next response */
  m2x_release_response(&response);
  /* Sleep for about a min, since it takes ~40 sec to create the device */
  sleep(15);

/* 5. list the values updated. */
  memset(&buf, 0, sizeof(buf));
  response = m2x_device_stream_list_values(ctx, &device_id, stream_name, NULL);
  if (m2x_is_success(&response) && response.raw) {
    printf("%s\n", response.raw);
    printf("%s\n", response.json);
  }

  m2x_release_response(&response);
  m2x_close(ctx);

  return 0;
}
