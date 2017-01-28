from django.conf.urls import url
from . import views

urlpatterns = [
  url(r'^$', views.index, name='index'),
  url(r'^hot/', views.questions, name='hot questions'),
  url(r'^question/(?P<id>\w+)/?$', views.question, name='question'),
  url(r'^ask/', views.ask_page, name='ask page'),
  url(r'^login/', views.login, name='login'),
  url(r'^signup/', views.signup, name='signup'),
  url(r'^user/', views.user, name='user'),
  url(r'^tag/(?P<tag>\w+)/?$', views.questions_tag, name='questions tag'),
]
