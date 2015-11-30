/*jslint browser: true*/
/*global $*/
/*global alert*/

$('#submit').click(function()        // someone must change id
    {
        //validation variable
        var valid = 0;

        //value variable
        var name = $('#nameAuth').val(),
            login = $('#loginAuth').val(),
            email = $('#emailAuth').val(),
            areStud = $('#hd-1').val(),
            group = $('#group').val(),
            password = $('#passAuth').val();
            /* 
            rpassword = $('#passAuth').val(); // change double id for pass and rep pass
            if(rpassword != password) {
                ++valid;
            }
            */
        if((valid != 0)&&(areStud === true)) {
            $.ajax({
                url: 'Registration',
                type: 'POST', //or get
                data: {
                    "Name : " +name,
                    "Login : " +login,
                    "E-mail : " +email,
                    "Password : " +password,
                    "Group : " +group,
                }
                success: function (data) {
                    var success = data.success;
                    if (success === true) {
                        alert('Now you can login!');
                    } else {
                        alert('Try another password or login');
                    }
                }
            });
        }
        // are this right?
         else if((valid != 0)&&(areStud === false)) {
            $.ajax({
                url: 'Registration',
                type: 'POST', //or get
                data: {
                    "Name : " +name,
                    "Login : " +login,
                    "E-mail : " +email,
                    "Password : " +password,
                }
                success: function (data) {
                    var success = data.success;
                    if (success === true) {
                        alert('Now you can login!');
                    } else {
                        alert('Try another password or login');
                    }
                }
            });
        }
        else {
            alert("Error!");
        }
    });
