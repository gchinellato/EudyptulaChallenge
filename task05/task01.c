#include <linux/init.h>
#include <linux/usb.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hid.h>

static int usb_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
	pr_alert("usb_probe\n");
	return 0;
}

static void usb_disconnect(struct usb_interface *intf)
{
	pr_alert("usb_disconnect\n");
}

static const struct usb_device_id usb_table[] = {
	{USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
		USB_INTERFACE_SUBCLASS_BOOT,
		USB_INTERFACE_PROTOCOL_KEYBOARD)},
	{},
};

MODULE_DEVICE_TABLE(usb, usb_table);

static struct usb_driver usb_keyboard = {
	.name = "USBKeyboard",
	.probe = usb_probe,
	.disconnect = usb_disconnect,
	.id_table = usb_table,
};

static int __init usb_init(void)
{
	int result;
	
	pr_alert("Loading USB module!\n");
	
	/* register this driver with the USB subsystem */
	result = usb_register(&usb_keyboard);
	if (result)
		pr_alert("usb_register failed. Error number %d\n", result);
	return result;
}

static void __exit usb_exit(void) 
{
	pr_alert("Unloading USB module\n");
	
	/* deregister this driver with the USB subsystem */
	usb_deregister(&usb_keyboard);
}

module_init(usb_init);
module_exit(usb_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("gchinellato");
MODULE_DESCRIPTION("Task 01");
MODULE_VERSION("0.1");
