# Robo-gid
Kvantorium project
<h1>introduction</h1>
So, these are all project files.
Project has such apps as:
<ul>
  <li>main app</li>
  <li>kvants app</li>
  <li>ronot_gid (default app with django settings etc.)</li>
  <li>kvant_projects</li>
  <li>timetable</li>
</ul>
Also there are such folders as static (images, js code, css etc.) and templates (all html5 files).
If you want to find any of those file go to static or templates folder and then to folder with the name of the app you are looking for.
Now I'd like to tell you about each app and tell you these things:
<ul>
  <li>What this app does</li>
  <li>it's main files</li>
  <li>it's urls structure</li>
</ul>

<h3>main app</h3>
Well, here is the app where all site's front end running.
Actually, this is the place where main html page are loading (see views.py file)
The main's url is "" (page loads when you enter only your domain, for example, 127.0.0:8000).
That's all about this app.

<h3>kvants app</h3>
Ok, this app is used to load all pages about different kvants.<br>
As you can see, there is a folder called 'data'. It's used for storing text info (desription from official site)
about different kvants and path to their path to files in 'static' folder.
So, all pages are rendered in views.py file (as usually), and its url structure is /kvants/kvant_name<br>
for example: 127.0.0:8000/kvants/it_kvant

<h3>kvants_projects app</h3>
This app is the most interesting one, but still unavailable.

<h3>timetable app</h2>
May be deleted soon
