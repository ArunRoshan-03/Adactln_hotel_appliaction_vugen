TC_05_book_hotel()
{
	randomnumber = rand() % 280; 
	lr_param_sprintf("P_fakeCreditCard", "4%04d98732109%03d", rand() % 10000, rand() % 1000); 
  	lr_param_sprintf("p_exp_year", "%04d", randomYear);
  	lr_param_sprintf("p_exp_month",  "%02d", randomMonth);
   	lr_param_sprintf("p_cc_cvv", "%04d", randomnumber);
   	
/*Correlation comment - Do not change!  Original value='36HIJFMV6O' Name ='C_order_id' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=C_order_id",
		"LB=id=\"order_no\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		LAST);
	
	web_submit_data("BookingConfirm.php",
		"Action={scheme}//{base_url}/BookingConfirm.php",
		"Method=POST",
		"RecContentType=text/html",
		"Referer={scheme}//{base_url}/BookHotel.php",
		"Snapshot=t44.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=first_name", "Value={p_username}", ENDITEM,
		"Name=last_name", "Value={p_lastname}", ENDITEM,
		"Name=address", "Value={p_address}", ENDITEM,
		"Name=cc_num", "Value={P_fakeCreditCard}", ENDITEM,
		"Name=cc_type", "Value={p_cc_type}", ENDITEM,
		"Name=cc_exp_month", "Value={p_exp_month}", ENDITEM,
		"Name=cc_exp_year", "Value={p_exp_year}", ENDITEM,
		"Name=cc_cvv", "Value={p_cc_cvv}", ENDITEM,
		"Name=hotel_name_hid", "Value={p_hotels}", ENDITEM,
		"Name=location_name_hid", "Value={p_locations}", ENDITEM,
		"Name=room_types_hid", "Value={p_room_types}", ENDITEM,
		"Name=rooms_no_hid", "Value=2", ENDITEM,
		"Name=arr_date_hid", "Value={p_pick_in}", ENDITEM,
		"Name=dep_date_hid", "Value={p_pick_out}", ENDITEM,
		"Name=no_days_hid", "Value={P_total_days}", ENDITEM,
		"Name=adults_room_hid", "Value=3", ENDITEM,
		"Name=children_room_hid", "Value=2", ENDITEM,
		"Name=price_night_hid", "Value={P_price_night}", ENDITEM,
		"Name=total_price_hid", "Value={p_total_price}", ENDITEM,
		"Name=gst_hid", "Value={p_gst_prices}", ENDITEM,
		"Name=final_price_hid", "Value={p_final_price}", ENDITEM,
		LAST);
		lr_param_sprintf("p_order_id", "%s", lr_eval_string("{C_order_id}"));
		
		lr_think_time(think_time);
	return 0;
}
