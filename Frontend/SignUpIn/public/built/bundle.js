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

	module.exports = __webpack_require__(1);


/***/ },
/* 1 */
/***/ function(module, exports) {

	import signin from 'pages/signin/signin';
	import signup from 'pages/signup/signup';

	class Main {
	  constructor() {
	    this._pageIndex = 0;
	    this._page = document.querySelector('.js-login');
	  }

	  _getPageContent() {
	    switch (this._pageIndex) {
	      case 0:
	        return signin.apply(this);
	      case 1:
	        return signup.apply(this);
	      default:
	        return 'хай';
	    }
	  }

	  updatePage(index) {
	    if (this._page.querySelector('div') === null) {
	      return;
	    }

	    this._page.querySelector('div').remove();
	    this._pageIndex = index;

	    const temp = this._getPageContent();
	    if (temp !== undefined) {
	      this._page.appendChild(this._getPageContent());
	    }
	  }

	  render() {
	    this._page.appendChild(this._getPageContent());
	  }
	}

	const index = new Main();
	index.render();

	export default index;

/***/ }
/******/ ]);