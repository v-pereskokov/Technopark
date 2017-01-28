import Signin from './pages/signin/signin';
import Signup from './pages/signup/signup';

class Main {
  constructor() {
    this._pageIndex = 0;
    this._page = document.querySelector('.js-login');
  }

  _getPageContent() {
    switch (this._pageIndex) {
      case 0:
        return Signin.apply(this);
      case 1:
        return Signup.apply(this);
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
