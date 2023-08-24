TC_06_click_my_itinerary_button()
{

	lr_think_time(67);

	web_custom_request("ocsp.comodoca.com_3", 
		"URL=http://ocsp.comodoca.com/", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0R0P0N0L0J0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14t\\x02F\\xF2Z\\\\B\\x12 \\xB5\\xBD]v\t\\xA6\\xBA\\\\\\xA3G\\xDF\\x04\\x14$\\xF2.N\\x0F\\xBD\\xCA\\xF7>)U\\xCAr\\x8Di\\x87VD\\xE9z\\x02\\x11\\x00\\xB7O\r\\xC5\\xE7\\xF1R$\\xE6\\xF7\\xBE\\xA3QF1&", 
		LAST);

	web_url("BookedItinerary.php", 
		"URL=https://adactinhotelapp.com/BookedItinerary.php", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://adactinhotelapp.com/BookingConfirm.php", 
		"Snapshot=t46.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}
