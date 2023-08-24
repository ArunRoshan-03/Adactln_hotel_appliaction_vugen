TC_05_book_hotel()
{

	lr_think_time(133);

	web_submit_data("BookingConfirm.php", 
		"Action=https://adactinhotelapp.com/BookingConfirm.php", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://adactinhotelapp.com/BookHotel.php", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=first_name", "Value=raja", ENDITEM, 
		"Name=last_name", "Value=kanna", ENDITEM, 
		"Name=address", "Value=trichy", ENDITEM, 
		"Name=cc_num", "Value=1234567890987654", ENDITEM, 
		"Name=cc_type", "Value=AMEX", ENDITEM, 
		"Name=cc_exp_month", "Value=12", ENDITEM, 
		"Name=cc_exp_year", "Value=2025", ENDITEM, 
		"Name=cc_cvv", "Value=123", ENDITEM, 
		"Name=hotel_name_hid", "Value=Hotel Cornice", ENDITEM, 
		"Name=location_name_hid", "Value=Brisbane", ENDITEM, 
		"Name=room_types_hid", "Value=Double", ENDITEM, 
		"Name=rooms_no_hid", "Value=7", ENDITEM, 
		"Name=arr_date_hid", "Value=24/08/2023", ENDITEM, 
		"Name=dep_date_hid", "Value=27/08/2023", ENDITEM, 
		"Name=no_days_hid", "Value=3", ENDITEM, 
		"Name=adults_room_hid", "Value=3", ENDITEM, 
		"Name=children_room_hid", "Value=2", ENDITEM, 
		"Name=price_night_hid", "Value=AUD $ 200", ENDITEM, 
		"Name=total_price_hid", "Value=AUD $ 610", ENDITEM, 
		"Name=gst_hid", "Value=AUD $ 61", ENDITEM, 
		"Name=final_price_hid", "Value=AUD $ 671", ENDITEM, 
		LAST);

	return 0;
}
