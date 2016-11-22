# -*- coding: utf-8 -*-
from django.core.management.base import BaseCommand, CommandError

from django.contrib.auth.models import User
from ask_slimov.models import Question, QuestionLike, Answer, AnswerLike

from random import choice, randint

class Command(BaseCommand):
    help = 'Creates fake likes'

    def add_arguments(self, parser):
        parser.add_argument('--number-answers',
                action='store',
                dest='number_answers',
                default=5,
                help='Number of likes for an answer'
        )
        parser.add_argument('--number-questions',
                action='store',
                dest='number_questions',
                default=5,
                help='Number of likes for a question'
        )

    def handle(self, *args, **options):
        number_answers = int(options['number_answers'])
        number_questions = int(options['number_questions'])

        users = User.objects.all()[1:]
        questions = Question.objects.all()

        for q in questions:
            self.stdout.write('question [%d]' % q.id)
            for i in range(0, number_questions):
                QuestionLike.objects.add_or_update(
                        author=choice(users),
                        question=q,
                        value=choice([-1, 1])
                        )

        answers = Answer.objects.all()

        for ans in answers:
            self.stdout.write('answer [%d]' % ans.id)
            for i in range(0, number_answers):
                AnswerLike.objects.add_or_update(
                        author=choice(users),
                        answer=ans,
                        value=choice([-1, 1])
                        )
