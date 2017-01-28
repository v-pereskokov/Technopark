from django.contrib import admin
from ask import models

class QuestionAdmin(admin.ModelAdmin):
  list_display=('title',)

class AnswerAdmin(admin.ModelAdmin):
  list_display=('text',)
class TagAdmin(admin.ModelAdmin):
  list_display=('text',)
class QuestionLikeAdmin(admin.ModelAdmin):
  list_display=('rating',)
class AnswerLikeAdmin(admin.ModelAdmin):
  list_display=('rating',)
class ProfileAdmin(admin.ModelAdmin):
  list_display=('user',)

admin.site.register(models.Question, QuestionAdmin)
admin.site.register(models.Answer, AnswerAdmin)
admin.site.register(models.Tag, TagAdmin)
admin.site.register(models.QuestionLike, QuestionLikeAdmin)
admin.site.register(models.AnswerLike, AnswerLikeAdmin)
admin.site.register(models.Profile, ProfileAdmin)

