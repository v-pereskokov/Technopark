from django.conf.urls import url
from . import views

urlpatterns = [
  url(r'^$', views.index, name='index'),
  url(r'^$(?P<page>\d+)/', views.index, name='index'),

  url(r'^hot/$', views.questions, name='hot questions'),
  url(r'^hot/?page=(?P<page>\d+)?/$', views.questions, name='hot questions'),

  url(r'^tag/(?P<tag>\w+)/?$', views.questions_tag, name='questions tag'),
  url(r'^tag/(?P<tag>\w+)/(?P<page>\d+)/$', views.questions_tag, name='questions tag'),

  url(r'^question/id(?P<id>\d+)/?$', views.question, name='question'), 
  url(r'^ask/', views.ask_page, name='ask page'),
  url(r'^login/', views.login, name='login'),
  url(r'^signup/', views.signup, name='signup'),
  url(r'^user/(?P<user_name>\w+)/?$', views.user, name='user'),
]
