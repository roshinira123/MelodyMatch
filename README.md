
# Melody Match (Song Recommender)

 
Authors: [Roshini Rangarajan](https://github.com/roshinira123), [Alison Ordentlich](https://github.com/aorde0012), [Darren Liang](https://github.com/DarrenLiang27), [Aheli Banerjee](https://github.com/abane029)

## Project Description
 * Why is it important or interesting to you? As music lovers, we love listening to music when we do our homework or want to have a fun time. However, sometimes we often run out of songs to listen to or want to discover some new music. That brings us to why we wanted to create Melody Match, the solution to our musical problem. 
 * What languages/tools/technologies do you plan to use? (This list may change over the course of the project) We plan to use C++, as it is the language we are the most knowledgeable about; GoogleTest, so we can have a testing suite to make sure our code works; Git, so we have a platform onto which we can update our project code files and utilize its Kanban Board; VSCode, which we will write our code in; and Spotify Web API, which has music resources we can develop and implement in our project to create necessary features.
 * What will be the input/output of your project? We will have a terminal-based output for our project to display on, and in this terminal, the user will be able to enter their favorite song and genres. They can also enter their mood. After this, the user could get an output for a list of potential songs that interest them and find new songs for them. Another input that the user could provide would be what songs they want to put in a playlist. The output could have all the songs in the playlist sorted.
 * What are the features that the project provides? The project will be able to provide a song based on various user input, such as mood, genre, or favorite song. The project then outputs a list of potential songs that could interest the user based on a recommendation algorithm. The list of songs is able to be sorted based on dates, alphabetical order, and other factors.
## User Interface Specification
### UML Class Diagram
![UML Diagram MelodyMatch](https://github.com/cs100/final-project-rrang020-abane029-dlian032-aorde001/assets/147006942/03f6efb4-6e5b-4e56-846f-f9f55f607e2d)
### Navigation Diagram
[Navigation Diagram MelodyMatch](https://github.com/cs100/final-project-rrang020-abane029-dlian032-aorde001/assets/53918739/ed5895a8-e965-4477-990f-956b2b0c3479)
### Screen Layouts
[Screen Layout MelodyMatch](https://github.com/cs100/final-project-rrang020-abane029-dlian032-aorde001/assets/53918739/b934cf3e-cf75-4d49-ac91-e33bb19ac051)

## Phase III - SOLID Principles
#### The Single Responsibility Principle: 
Throughout the program, we use this principle because some of the classes have one thing that they focus on and therefore there is only one thing to change. This can be seen in the SongsDataFilter(), SongsDataManager(), and Song() classes. These classes focus on one purpose whether that be storing Song information or managing the songs in vectors. This is also applied in the LoginAuth() class, where its sole responsibility is just logging in users. This principle helped us focus our different issues into different classes, and help abstract our work so we can better work on different parts together. 

#### Open-Closed Principle: 
We also applied this principle, because many of these classes are easily open to be extended but prevent modification. This can be seen in the SongDataFilter() class, this class can be extended to filter a range of different attributes other than genre, artist, and mood. It can be extended to maybe filter by the user's favorite decade of music released or by the user's favorite albums. However, it prevents modification because the class has one purpose which is to filter and output a personalized list of songs. This principle helps us by allowing us to be able to scale the project in the future or add more elements if time permits, without disrupting the functionality of the other classes. 

 ## Final deliverable
  All group members will give a demo to the reader during lab time. You should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
  Before the demo, you should do the following:
  * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
  * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
  * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
  Screenshots of the input/output after running your application
 ## Installation/Usage
  Using git, clone the repository, and ```cd``` into it.
```
  git clone https://github.com/cs100/final-project-rrang020-abane029-dlian032-aorde001.git
```
```
  cd final-project-rrang020-abane029-dlian032-aorde001
```


  Our project utilizes ```cmake``` and ```make``` to create the executables to run our project. Assuming the necessary extensions are installed, enter the following commands to create the excecutables:

```
  cmake .
```
```
  make
```
  The executable:
```
  ./MelodyMatch
```
  will be created.

  Running the executable ```./MelodyMatch``` will begin the music recommending software. 
 ## Testing
  How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.

 ## ValGrind Screenshots

 ### loginAuth Test
 ![LoginAuthTest Valgrind Screenshot](Valgrind%20Screenshots/LoginAuthTest%20valgrind.png)

