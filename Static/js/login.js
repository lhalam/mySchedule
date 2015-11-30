/*jslint browser: true*/
/*global $*/
/*global alert*/


$(document).ready(function () {
    'use strict';
    var authorization = function () {
        var em = $('#emailAuth').val(), // get EMAIL
            ps = $('#passAuth').val();   // get password
        $.ajax({
            url: 'login',
			type: 'GET',
			data: {"E-mail : " +em, "Password : " +ps}, // todo change the data
	/*
         *  verification interaction by server and
         *  client(browser)
         */
            success: function (data) {
                var success = data.success;
                if (success === true) {
                    window.location('after_log.html'); // page after login
                } else {
                    alert('Try another password or login');
                }
            }
        });
    };
	$("#submit").click(authorization);
});
