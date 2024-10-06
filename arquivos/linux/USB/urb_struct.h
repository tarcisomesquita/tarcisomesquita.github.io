struct usbfs_urb {
	unsigned char type;
	unsigned char endpoint;
	int status;
	unsigned int flags;
	void *buffer;
	int buffer_length;
	int actual_length;
	int start_frame;
	int number_of_packets;
	int error_count;
	unsigned int signr;
	void *usercontext;
	struct usbfs_iso_packet_desc iso_frame_desc[0];
};

struct usbfs_iso_packet_desc {
	unsigned int length;
	unsigned int actual_length;
	unsigned int status;
};

enum usbfs_urb_type {
	USBFS_URB_TYPE_ISO = 0,
	USBFS_URB_TYPE_INTERRUPT = 1,
	USBFS_URB_TYPE_CONTROL = 2,
	USBFS_URB_TYPE_BULK = 3,
};

