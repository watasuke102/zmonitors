#ifndef ZMONITORS_H
#define ZMONITORS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <zmonitors-util.h>

/* seat */

struct zms_seat_private;

struct zms_seat {
  struct zms_seat_private *priv;
};

/* output */

struct zms_output_private;

struct zms_output {
  struct zms_output_private *priv;
};

/* compositor */

struct zms_compositor_private;

struct zms_compositor {
  struct zms_compositor_private *priv;

  struct zms_seat *seat;
  struct zms_output *output;
};

struct zms_compositor *zms_compositor_create();

void zms_compositor_destroy(struct zms_compositor *compositor);

void zms_compositor_flush_clients(struct zms_compositor *compositor);

void zms_compositor_dispatch_event(
    struct zms_compositor *compositor, int timeout);

#ifdef __cplusplus
}
#endif

#endif  //  ZMONITORS_H
