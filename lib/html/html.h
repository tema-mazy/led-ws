const char _MIOT_HEAD[] PROGMEM           = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><meta http-equiv=\"X-UA-Compatible\" content=\"ie=edge\"><meta http-equiv='refresh' content='60;url=/' /><title>{title}</title>";
const char _MIOT_STYLE[] PROGMEM          = "<style> body{margin:0;padding:104px 0 78px;background:#f4f4ff;font-family:Arial,Helvetica,sans-serif;font-size:14px;color:#242939}ul{margin:0;padding:0;list-style:none}a{color:#4c7ffb;text-decoration:none}.navbar{padding:20px 0;position:fixed;top:0;left:0;right:0;z-index:999;background:#fff;border-radius:0 0 24px 24px}.navbar .container{display:-webkit-box;display:-ms-flexbox;display:flex;-webkit-box-pack:justify;-ms-flex-pack:justify;justify-content:space-between;-webkit-box-align:start;-ms-flex-align:start;align-items:flex-start}.navbar .title{font-size:18px;font-weight:700}.navbar .active,.status{font-size:75%}.badge{width:45px;height:20px;border:3px solid transparent;font-size:0;border-radius:18px;display:-webkit-box;display:-ms-flexbox;display:flex;-webkit-box-pack:end;-ms-flex-pack:end;justify-content:flex-end;cursor:pointer}.badge span{width:20px;height:20px;background-color:#fff;border-radius:50%}.badge.badge-on{background-color:#4c7ffb;border-color:#4c7ffb}.badge.badge-off{background-color:#ccc;-webkit-box-pack:start;-ms-flex-pack:start;justify-content:flex-start}.navbar .badge{margin-bottom:5px}.navbar .status{color:#888}.container{max-width:600px;margin:0 auto;padding:0 20px}.footer{padding:10px 0;position:fixed;bottom:0;left:0;right:0;z-index:999;background:#fff;border-radius:12px 12px 0 0}.btn{display:inline-block;font-weight:400;color:#212529;text-align:center;vertical-align:middle;cursor:pointer;background-color:#4c7ffb;border:none;padding:.375rem .75rem;font-size:1rem;line-height:1.5;border-radius:.25rem;color:#fff}.btn-sm{padding:2px 10px;font-size:12px}.btn-sm i{font-size:14px}.nav-tabs{margin-bottom:20px;display:-webkit-box;display:-ms-flexbox;display:flex;-webkit-box-pack:center;-ms-flex-pack:center;justify-content:center;font-size:12px;color:#888}.nav-tabs li{padding:0 10px 8px 10px;position:relative;cursor:pointer}.nav-tabs .active{color:#4c7ffb}.nav-tabs .active::after{content:\"\";width:4px;height:4px;margin-left:-2px;display:inline-block;background-color:#4c7ffb;border-radius:50%;position:absolute;left:50%;bottom:0}.effects-list{margin:0 -10px;display:-webkit-box;display:-ms-flexbox;display:flex;-ms-flex-wrap:wrap;flex-wrap:wrap}.effects-list li{width:50%;padding:0 10px;margin-bottom:10px;-webkit-box-sizing:border-box;box-sizing:border-box}.effects-list label{position:relative;cursor:pointer}.effects-list label span{padding:5px 10px;display:block;border-radius:3px}.effects-list input[type=checkbox]{position:absolute;opacity:0}.effects-list input[type=checkbox]+span{background-color:#fff}.effects-list input[type=checkbox]:checked+span{background-color:#4c7ffb;color:#fff}.slider{-webkit-appearance:none;width:100%;height:5px;border-radius:5px;background:#d3d3d3;outline:0;opacity:.7;-webkit-transition:.2s;-webkit-transition:opacity .2s;transition:opacity .2s}.slider:hover{opacity:1}.slider::-webkit-slider-thumb{-webkit-appearance:none;appearance:none;width:15px;height:15px;border-radius:50%;background:#4c7ffb;cursor:pointer}.tab-content-item{display:none}.tab-content-item.active{display:block}.settings-list .card{padding:10px;margin-bottom:20px;display:-webkit-box;display:-ms-flexbox;display:flex;-ms-flex-wrap:wrap;flex-wrap:wrap;background-color:#fff;border-radius:6px}.settings-list input[type=range]{width:100%}.settings-list label{margin-bottom:10px;display:block}.settings-list input[type=checkbox]+label{margin-bottom:0}.controls{margin-top:30px}@media screen and (max-width:767px){.hide-on-mobile{display:none}}@media screen and (min-width:768px){.hide-on-desktop{display:none}.effects-list li{width:33%}.settings-list{margin:0 -10px;display:-webkit-box;display:-ms-flexbox;display:flex;-ms-flex-wrap:wrap;flex-wrap:wrap}.settings-list li{width:50%;padding:0 10px;-webkit-box-sizing:border-box;box-sizing:border-box}} </style>";
const char _MIOT_BODY[] PROGMEM           = "</head><body><div class=\"navbar\"><div class=\"container\"><div class=\"brand\"><div class=\"title\">X-Mas Lights</div><div class=\"active\">{mode}</div></div><div class=\"status\"><a href=\"/state?r={millis}\" class=\"badge badge-{statebage}\"><span>{state}</span></a><span>Вмк/Вимк</span></div><div class=\"status\"><a href=\"/next?r={millis}\" class=\"btn btn-sm\">Наступний <i>&rarr;</i></a></div></div></div><div class=\"main\" id=\"main\"><div class=\"container\"><ul class=\"nav-tabs\"><li class=\"active\">Ефекти</li><li>Налаштування</li></ul><form action=\"/save\" id=\"saveForm\" name=\"saveForm\" method=\"GET\"><div class=\"tab-content\"><div class=\"tab-content-item active\" id=\"tab-effects\"><ul class=\"effects-list\"> {effects} </ul></div><div class=\"tab-content-item\" id=\"tab-settings\"><ul class=\"settings-list\"><li><div class=\"card\"><label for='brt'>Яскравість: <span id='bvo'>{brt}</span></label><input type='range' min='1' max='255' value='{brt}' class='slider' id='brt' name='brt'></div></li><li><div class=\"card\"><label for='del'>Зміна ефектів через: <span id=\"dvo\">{del}</span>с</label><input type='range' min='1' max='600' value='{del}' class='slider' id='del' name='del'></div></li><li><div class=\"card\"><input type='checkbox' {brbr} value='1' id='brbr' name='brbr'><label for='brbr'>\"Дихання\" яскравістю</label></div></li><li><div class=\"card\"><input type='checkbox' {huec} value='1' id='huec' name='huec'><label for='huec'>Циркуляція кольору</label></div></li><li><div class=\"card\"><label for='hues'>Швидкість циркуляціі: <span id=\"svo\">{hues}</span>mс</label><input type='range' min='5' max='300' step='5' value='{hues}' class='slider' id='hues' name='hues'></div></li><li><div class=\"card\"><input type='checkbox' {palc} value='1' id='palc' name='palc'><label for='palc'>Зміна палітр</label></div></li><li><div class=\"card\"><label for='pals'>Швидкість зміни: <span id=\"pvo\">{pals}</span>с</label><input type='range' min='1' max='120' value='{pals}' class='slider' id='pals' name='pals'></div></li><li><div class=\"card\"><label for='pals'>Швидкість снігу: <span id=\"svvo\">{svv}</span>с/мс</label><input type='range' min='0' max='1000' value='{svv}' class='slider' id='svv' name='svv'></div></li></ul></div></div><div class=\"controls\"><button class=\"btn\" onclick=\"document.getElementById('saveForm').submit();\">Зберегти</button><button class=\"btn\" onclick=\"if (confirm('Скинути всі Налаштування?')) { document.location='/reset?r={millis}'; }; \">RESET</button></div></div></div><div class=\"footer\"><div class=\"container\"><p> Wi-Fi signal: {signal} dBi</p><p>&copy; 2020 Mazy IoT, design Alex Lunev</p></div></div></form></body><!-- _MIOT_SCRIPT --><script> var bslider = document.getElementById('brt'); var bvo = document.getElementById('bvo'); bvo.innerHTML = bslider.value; bslider.oninput = function() { bvo.innerHTML = this.value; }; var dslider = document.getElementById('del'); var dvo = document.getElementById('dvo'); dvo.innerHTML = dslider.value; dslider.oninput = function() { dvo.innerHTML = this.value; }; var sslider = document.getElementById('hues'); var svo = document.getElementById('svo'); svo.innerHTML = sslider.value; sslider.oninput = function() { svo.innerHTML = this.value; }; var pslider = document.getElementById('pals'); var pvo = document.getElementById('pvo'); pvo.innerHTML = pslider.value; pslider.oninput = function() { pvo.innerHTML = this.value; }; var ssslider = document.getElementById('svv'); var svvo = document.getElementById('svvo'); svvo.innerHTML = ssslider.value; ssslider.oninput = function() { svvo.innerHTML = this.value; }; var tabLinks = document.querySelectorAll(\"#main .nav-tabs li\"), tabContents = document.querySelectorAll(\"#main .tab-content > div\"); tabLinks.forEach(function(tab, index){ tab.addEventListener(\"click\", function(){ tabLinks.forEach(function(item){ item.classList.remove(\"active\") }); this.classList.add(\"active\"); tabContents.forEach(function(item){ item.classList.remove(\"active\") }); tabContents[index].classList.add(\"active\"); }); }); </script><!-- /_MIOT_SCRIPT --></html>";
const char _MIOT_SCRIPT[] PROGMEM         = "<script> var bslider = document.getElementById('brt'); var bvo = document.getElementById('bvo'); bvo.innerHTML = bslider.value; bslider.oninput = function() { bvo.innerHTML = this.value; }; var dslider = document.getElementById('del'); var dvo = document.getElementById('dvo'); dvo.innerHTML = dslider.value; dslider.oninput = function() { dvo.innerHTML = this.value; }; var sslider = document.getElementById('hues'); var svo = document.getElementById('svo'); svo.innerHTML = sslider.value; sslider.oninput = function() { svo.innerHTML = this.value; }; var pslider = document.getElementById('pals'); var pvo = document.getElementById('pvo'); pvo.innerHTML = pslider.value; pslider.oninput = function() { pvo.innerHTML = this.value; }; var ssslider = document.getElementById('svv'); var svvo = document.getElementById('svvo'); svvo.innerHTML = ssslider.value; ssslider.oninput = function() { svvo.innerHTML = this.value; }; var tabLinks = document.querySelectorAll(\"#main .nav-tabs li\"), tabContents = document.querySelectorAll(\"#main .tab-content > div\"); tabLinks.forEach(function(tab, index){ tab.addEventListener(\"click\", function(){ tabLinks.forEach(function(item){ item.classList.remove(\"active\") }); this.classList.add(\"active\"); tabContents.forEach(function(item){ item.classList.remove(\"active\") }); tabContents[index].classList.add(\"active\"); }); }); </script>";
