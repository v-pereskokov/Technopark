  $('.likebutton').click(function () {    
    $.ajax({
        url: "{% url 'question_like' %}",
        type: "POST",
        data: {'id': $(this).attr('dataid'), 'like' : '1','csrfmiddlewaretoken': '{{ csrf_token }}'},
        success: function(response) {
          $(response.qstyleid).text(response.qrating);
          $(response.qstyleid).removeClass().addClass(response.qstyle);
          $(response.ustyleid).text(response.urating);
          $(response.ustyleid).removeClass().addClass(response.ustyle);
          $(response.likebuttonid).removeClass().addClass(response.likebuttonstyle);
          $(response.dislikebuttonid).removeClass().addClass(response.dislikebuttonstyle);
            
            }
        });
  });

  $('.alikebutton').click(function () {    
    $.ajax({
        url: "{% url 'answer_like' %}",
        type: "POST",
        data: {'id': $(this).attr('dataid'), 'like' : '1','csrfmiddlewaretoken': '{{ csrf_token }}'},
        success: function(response) {
          $(response.astyleid).text(response.arating);
          $(response.astyleid).removeClass().addClass(response.astyle);
          $(response.ustyleid).text(response.urating);
          $(response.ustyleid).removeClass().addClass(response.ustyle);
          $(response.likebuttonid).removeClass().addClass(response.likebuttonstyle);
          $(response.dislikebuttonid).removeClass().addClass(response.dislikebuttonstyle);
            
            }
        });
  });

  $('.anscheck').click(function() {
    $.ajax({
      url: "{% url 'answer_check' %}",
      type: "POST",
      data: {'ansid' : $(this).attr('ansid'), 'qid' : $(this).attr('qid'), 'csrfmiddlewaretoken': '{{ csrf_token }}'},
      success: function(response) {
        if(response.iscorrect){
          $(".check" + response.ansid).html('<img src="{% static 'images/check.png' %}" width="30">')
        }
        else{
          $(".check" + response.ansid).html('')
        }
      }
    });

  }); 
