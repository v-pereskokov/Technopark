proxy_buffering on;
proxy_cache_path /var/cache/nginx levels=1:2 keys_zone=cache:10m max_size=32m;

upstream gunicorn {
  server localhost:8081;
}

server {
  listen 80;
  server_name topquestion.com;
  root /var/www/environment/topquestion;
  access_log /var/www/environment/topquestion/logs/access.log;
  error_log /var/www/environment/topquestion/logs/error.log;    

  location / {
    proxy_pass http://gunicorn;
    proxy_set_header Host $host;
    proxy_set_header X-Real-IP $remote_addr;
    proxy_cache cache;
    proxy_cache_valid any 1h;
  }

  location ~\.(html)$ {
    root /var/www/environment/topquestion/templates;
    index index.html;
  }

  location ^~ /uploads/ {
    root /var/www/environment/topquestion/;
  }

  location ~* \.(css|js|jpg|jpeg|png|ico)$ {
    root /var/www/environment/topquestion/static;
    expires 30d;
    add_header Cache-Control private;
  }
}
