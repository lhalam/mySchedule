/*jslint browser: true*/
/*global $*/
/*global alert*/


$(document).ready(function () {
    'use strict';
    var authorization = function () {
        var em = $('input[id=emailAuth]'.val()), // get EMAIL
            ps = $('input[id=passAuth]'.val());   // get password
        $.ajax({
            type: "POST",
            url: "base_request.cpp",   //server href
            data: "Email: " + em + "&password=" + ps, //send data to server
            dataType: "json",
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
});
