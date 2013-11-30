#include<cstdio>
#include<libusb.h>

// TODO: Change these values to those from the real DAQ
#define DAQ_VID 0x3923
#define DAQ_PID 0x717a

void printdev(libusb_device *dev);

int main()
{
  libusb_device **devs;
  libusb_context *ctx = NULL;
  int r;
  ssize_t cnt;
  r = libusb_init(&ctx);
  if (r<0)
  {
    fprintf(stderr,"Initialization Error: %d\n",r);
    return 1;
  }
  libusb_set_debug(ctx,3);

  libusb_device_handle *dev;
  dev = libusb_open_device_with_vid_pid(ctx,DAQ_VID,DAQ_PID);
  if (dev<=0)
  {
    fprintf(stderr,"Error opening device: %d\n",dev);
    return 1;
  }
  printf("DAQ Found!\n");

  r=libusb_kernel_driver_active(dev,1);
  printf("Kernel Driver Active: ");
  if (r==1) {
    printf("Yes\n");
  } else if (r==0) {
    printf("No\n");
  } else {
    printf("Error: %d\n",r);
  }

  r=libusb_claim_interface(dev,1);
  if (r!=0) {
    printf("Error claiming interface: %d\n", r);
    return 1;
  }

  libusb_close(dev);
  libusb_exit(ctx);
  return 0;
}
