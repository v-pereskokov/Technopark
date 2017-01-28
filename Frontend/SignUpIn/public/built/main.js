/******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};

/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {

/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId])
/******/ 			return installedModules[moduleId].exports;

/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			exports: {},
/******/ 			id: moduleId,
/******/ 			loaded: false
/******/ 		};

/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);

/******/ 		// Flag the module as loaded
/******/ 		module.loaded = true;

/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}


/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;

/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;

/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "";

/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(0);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */
/***/ function(module, exports, __webpack_require__) {

	'use strict';

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});

	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

	var _signin = __webpack_require__(1);

	var _signin2 = _interopRequireDefault(_signin);

	var _signup = __webpack_require__(6);

	var _signup2 = _interopRequireDefault(_signup);

	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

	var Main = function () {
	  function Main() {
	    _classCallCheck(this, Main);

	    this._pageIndex = 0;
	    this._page = document.querySelector('.js-login');
	  }

	  _createClass(Main, [{
	    key: '_getPageContent',
	    value: function _getPageContent() {
	      switch (this._pageIndex) {
	        case 0:
	          return _signin2.default.apply(this);
	        case 1:
	          return _signup2.default.apply(this);
	        default:
	          return 'хай';
	      }
	    }
	  }, {
	    key: 'updatePage',
	    value: function updatePage(index) {
	      if (this._page.querySelector('div') === null) {
	        return;
	      }

	      this._page.querySelector('div').remove();
	      this._pageIndex = index;

	      var temp = this._getPageContent();
	      if (temp !== undefined) {
	        this._page.appendChild(this._getPageContent());
	      }
	    }
	  }, {
	    key: 'render',
	    value: function render() {
	      this._page.appendChild(this._getPageContent());
	    }
	  }]);

	  return Main;
	}();

	var index = new Main();
	index.render();

	exports.default = index;

/***/ },
/* 1 */
/***/ function(module, exports, __webpack_require__) {

	'use strict';

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});

	var _form = __webpack_require__(2);

	var _form2 = _interopRequireDefault(_form);

	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

	var form = new _form2.default({
	  el: document.createElement('div'),
	  data: {
	    title: 'login',
	    url: '/api/login',
	    fields: [{
	      name: 'login',
	      type: 'text',
	      label: 'Username',
	      required: true
	    }, {
	      name: 'password',
	      type: 'password',
	      label: 'Password',
	      required: true
	    }],
	    controls: [{
	      text: 'Sign in',
	      attrs: {
	        type: 'submit'
	      }
	    }]
	  }
	});

	function Signin() {
	  var _this = this;

	  var formSignin = document.createElement('div');
	  formSignin.appendChild(form.el);

	  var temp1 = document.createElement('div');
	  temp1.innerHTML = '\n  <div class="link-signup z-depth-1">\n    <span><a class="link1">Create an account.</a></span>\n  </div>\n ';
	  temp1.querySelector('.link1').addEventListener('click', function () {
	    _this.updatePage(1);
	  });
	  formSignin.appendChild(temp1);

	  var temp2 = document.createElement('div');
	  temp2.innerHTML = '\n  <div class="link-signup z-depth-1">\n    <span><a class="link2">Go</a></span>\n  </div>\n ';
	  temp2.querySelector('.link2').addEventListener('click', function () {
	    _this.updatePage(2);
	  });
	  formSignin.appendChild(temp2);

	  return formSignin;
	}

	exports.default = Signin;

/***/ },
/* 2 */
/***/ function(module, exports, __webpack_require__) {

	'use strict';

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});

	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

	var _button = __webpack_require__(3);

	var _button2 = _interopRequireDefault(_button);

	var _plural = __webpack_require__(4);

	var _plural2 = _interopRequireDefault(_plural);

	var _requests = __webpack_require__(5);

	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

	var Form = function () {
	  function Form() {
	    var options = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : { data: {} };

	    _classCallCheck(this, Form);

	    this.data = options.data;
	    this.el = options.el;
	    this.count = 0;
	    this.requeredFields = {};
	    this.render();
	  }

	  _createClass(Form, [{
	    key: '_addError',
	    value: function _addError() {
	      var formData = this._getFormData();
	      var fields = Object.keys(this.requeredFields);

	      for (var i = 0; i < fields.length; i += 1) {
	        var temp = fields[i];
	        if (this.requeredFields[temp] === true && formData[temp] === '') {
	          this.el.querySelector('.' + temp + 'P').className = 'input-field ' + temp + 'P error';
	        }
	      }
	    }
	  }, {
	    key: '_comparePassword',
	    value: function _comparePassword() {
	      var formData = this._getFormData();

	      if (formData.password1 !== undefined && formData.password1 !== formData.password2 && formData.password1 !== '' && formData.password2 !== '') {
	        this.el.querySelector('.ui-error').innerHTML = 'Пароли не совпадают';
	        this.el.querySelector('.ui-error').style.display = 'block';
	        return false;
	      }

	      this.el.querySelector('.ui-error').innerHTML = '';
	      this.el.querySelector('.ui-error').style.display = 'none';
	      return true;
	    }
	  }, {
	    key: '_onBlur',
	    value: function _onBlur(event) {
	      this._comparePassword();

	      var temp = event.target;
	      if (temp.value === '' && this.requeredFields[temp.name] === true) {
	        this.el.querySelector('.' + temp.name + 'P').className = 'input-field ' + temp.name + 'P error';
	      }
	    }
	  }, {
	    key: '_onFocus',
	    value: function _onFocus(event) {
	      var temp = event.target.name;
	      if (this.el.querySelector('.' + temp + 'P').className !== 'input-field ' + temp) {
	        this.el.querySelector('.' + temp + 'P').className = 'input-field ' + temp + 'P';
	      }
	    }
	  }, {
	    key: '_checkFill',
	    value: function _checkFill() {
	      var _this = this;

	      var formData = this._getFormData();
	      return Object.keys(formData).every(function (element) {
	        if (formData[element] === '' && _this.requeredFields[element] === true) {
	          return false;
	        }

	        return true;
	      });
	    }
	  }, {
	    key: '_onSubmit',
	    value: function _onSubmit() {
	      var _this2 = this;

	      this.el.addEventListener('submit', function (event) {
	        event.preventDefault();

	        var compare = _this2._comparePassword();

	        if (_this2._checkFill() === false || compare === false) {
	          _this2._addError();
	          return;
	        }

	        var formData = _this2._getFormData();

	        if (formData.password1 !== undefined) {
	          formData.password = formData.password1;
	          delete formData.password1;
	          delete formData.password2;
	        }

	        var result = (0, _requests.jsonRequest)(_this2.data.url, formData);
	        var obj = JSON.parse(result);

	        if (typeof obj.login === 'undefined') {
	          window.welcome.innerHTML = '<span class="redError">' + obj.reason + '</span>';
	          window.welcome.hidden = false;
	        } else {
	          if (_this2.data.title === 'login') {
	            var count = obj.amount;
	            var name = obj.login;

	            window.welcome.innerHTML = '<span>\u041F\u0440\u0438\u0432\u0435\u0442, ' + name + '. \u0422\u044B \u0437\u0430\u0448\u0435\u043B ' + count + ' ' + (0, _plural2.default)(count, ['раз', 'раза', 'раз'], 'rus') + '</span>';
	          } else {
	            window.updatePage(0);
	          }
	        }
	      });
	    }
	  }, {
	    key: '_getFormData',
	    value: function _getFormData() {
	      var form = this.el.querySelector('form');
	      var elements = form.elements;
	      var fields = {};

	      Object.keys(elements).forEach(function (element) {
	        var name = elements[element].name;
	        var value = elements[element].value;

	        if (!name) {
	          return;
	        }

	        fields[name] = value;
	      });

	      return fields;
	    }
	  }, {
	    key: 'on',
	    value: function on(type, callback) {
	      this.el.addEventListener(type, callback);
	    }
	  }, {
	    key: '_addEvents',
	    value: function _addEvents() {
	      var _this3 = this;

	      this._onSubmit();

	      var form = this.el.querySelector('form');
	      var elements = form.elements;

	      Object.keys(elements).forEach(function (element) {
	        if (!elements[element].name) {
	          return;
	        }
	        elements[element].addEventListener('blur', _this3._onBlur.bind(_this3));
	        elements[element].addEventListener('focus', _this3._onFocus.bind(_this3));
	      });
	    }
	  }, {
	    key: '_getFieldsRequered',
	    value: function _getFieldsRequered() {
	      var _this4 = this;

	      var _data$fields = this.data.fields,
	          fields = _data$fields === undefined ? [] : _data$fields;


	      fields.forEach(function (field) {
	        if (field.required === true) {
	          _this4.requeredFields[field.name] = true;
	        } else {
	          _this4.requeredFields[field.name] = false;
	        }
	      });
	    }
	  }, {
	    key: '_installControls',
	    value: function _installControls() {
	      var _this5 = this;

	      var _data$controls = this.data.controls,
	          controls = _data$controls === undefined ? [] : _data$controls;


	      controls.forEach(function (data) {
	        var control = new _button2.default({ text: data.text }).render();
	        _this5.el.querySelector('.js-controls').appendChild(control.el);
	      });
	    }
	  }, {
	    key: '_getFields',
	    value: function _getFields() {
	      var _this6 = this;

	      var _data$fields2 = this.data.fields,
	          fields = _data$fields2 === undefined ? [] : _data$fields2;


	      return fields.map(function (field) {
	        _this6.count += 1;
	        return '\n        <div class="input-field ' + field.name + 'P">\n          <label for="' + field.name + '">' + field.label + '</label>\n          <input type="' + field.type + '" tabindex="' + _this6.count + '" name="' + field.name + '">\n          <i>This field is requered</i>\n        </div>\n      ';
	      }).join(' ');
	    }
	  }, {
	    key: '_updateHtml',
	    value: function _updateHtml() {
	      this.el.innerHTML = '\n    <div class="ui-error z-depth-1"></div>\n    <form class="ui-form z-depth-1">\n      <div>\n        ' + this._getFields() + '\n      </div>\n      <div class="js-controls">\n      </div>\n    <form>\n  ';
	    }
	  }, {
	    key: 'render',
	    value: function render() {
	      this._updateHtml();
	      this._installControls();
	      this._getFieldsRequered();
	      this._addEvents();
	    }
	  }]);

	  return Form;
	}();

	exports.default = Form;

/***/ },
/* 3 */
/***/ function(module, exports) {

	'use strict';

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});

	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

	var Button = function () {
	  function Button(options) {
	    _classCallCheck(this, Button);

	    this.text = options.text;
	    this.attrs = options.attrs || [];
	    this.el = document.createElement('button');
	  }

	  _createClass(Button, [{
	    key: 'setAttrs',
	    value: function setAttrs(attrs) {
	      var _this = this;

	      Object.keys(attrs).forEach(function (name) {
	        _this.el.setAttribute(name, attrs[name]);
	      });
	    }
	  }, {
	    key: 'toString',
	    value: function toString() {
	      return this.el.outerHTML;
	    }
	  }, {
	    key: 'render',
	    value: function render() {
	      this.el.innerHTML = this.text;
	      this.el.classList.add('waves-effect', 'waves-light', 'btn', 'ui-button');
	      this.setAttrs(this.attrs);
	      return this;
	    }
	  }]);

	  return Button;
	}();

	exports.default = Button;

/***/ },
/* 4 */
/***/ function(module, exports) {

	'use strict';

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	exports.default = plural;
	function russianPluralRule(number) {
	  var lastDigit = number % 10;
	  if (lastDigit === 1 && number !== 11) {
	    return 0;
	  }
	  if ([2, 3, 4].indexOf(lastDigit) >= 0 && [12, 13, 14].indexOf(number) < 0) {
	    return 1;
	  }
	  return 2;
	}

	function plural(number, forms, lang) {
	  var num = number;
	  if (typeof number === 'string') {
	    num = parseInt(number, 0);
	  }
	  switch (lang) {
	    case 'rus':
	      return forms[russianPluralRule(num)];
	    default:
	      throw new Error('plural does not support ' + lang);
	  }
	}

/***/ },
/* 5 */
/***/ function(module, exports) {

	'use strict';

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	exports.jsonRequest = jsonRequest;
	exports.getRequest = getRequest;
	function jsonRequest(url, data) {
	  var xhr = new XMLHttpRequest();
	  xhr.open('POST', url, false);
	  xhr.setRequestHeader('Content-Type', 'application/json');
	  xhr.send(JSON.stringify(data));
	  return xhr.responseText;
	}

	function getRequest(url) {
	  var xhr = new XMLHttpRequest();
	  xhr.open('GET', url, false);
	  xhr.send();
	  return xhr.responseText;
	}

/***/ },
/* 6 */
/***/ function(module, exports, __webpack_require__) {

	'use strict';

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});

	var _form = __webpack_require__(2);

	var _form2 = _interopRequireDefault(_form);

	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

	var form = new _form2.default({
	  el: document.createElement('div'),
	  data: {
	    title: 'signup',
	    url: '/api/signup',
	    fields: [{
	      name: 'login',
	      type: 'text',
	      label: 'Username',
	      required: false
	    }, {
	      name: 'email',
	      type: 'email',
	      label: 'Email',
	      required: true
	    }, {
	      name: 'password1',
	      type: 'password',
	      label: 'Password',
	      required: true
	    }, {
	      name: 'password2',
	      type: 'password',
	      label: 'Repeat password',
	      required: true
	    }],
	    controls: [{
	      text: 'Sign up',
	      attrs: {
	        type: 'submit'
	      }
	    }]
	  }
	});

	function signup() {
	  var _this = this;

	  var formSignup = document.createElement('div');
	  formSignup.appendChild(form.el);

	  var temp1 = document.createElement('div');
	  temp1.innerHTML = '\n  <div class="link-signup z-depth-1">\n    <span><a class="link1">\u0412\u0435\u0440\u043D\u0443\u0442\u044C\u0441\u044F \u043D\u0430\u0437\u0430\u0434</a></span>\n  </div>\n ';
	  temp1.querySelector('.link1').addEventListener('click', function () {
	    _this.updatePage(0);
	  });
	  formSignup.appendChild(temp1);

	  return formSignup;
	}

	exports.default = signup;

/***/ }
/******/ ]);