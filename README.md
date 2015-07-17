Puzzle Game App Demo for Appiaries (iOS)
===========================

## About This App

This is a Puzzle App demo for Appiaries.  
Users register with their email address, and login with Login ID and Password.  
There are several stages for this game.  
Every time users clear the stage, in accord with the time took, names will appear on ranking lists.  
There are "Time Ranking" list and "First-Come Ranking" list.  
In order to keep track of orders for "First-Come",  
we will be using "Sequence API" provided by Appiaries.

## Updates

* [2015-07-17] Upgraded the _Appiaries SDK_ vesion from _**"v.2.0.2"**_ to _**"v.2.0.3"**_.
* [2015-06-29] Upgraded the _Appiaries SDK_ vesion from _**"v.2.0.0"**_ to _**"v.2.0.2"**_.
* [2015-06-23] Upgraded the _Appiaries SDK_ vesion from _**"Appiaries SDK v.1.4.0"**_ to _**"Appiaries SDK v.2.0.0"**_.

## Requirements

It does not require you an Appiaries account if you just want to build and run the app.  
Although it requires server-side data stored on Appiaries,  
it is already configured as default to retrieve the ones from our demo account.  
If you intend to customize the server-side data, you need a sign-up.  
Runs on iOS 7.1 or higher.

## License

You may freely use, modify, or distribute the source codes provided.

## Appiaries API Services Used

* <a href="http://docs.appiaries.com/?p=11015&lang=en">JSON Data API</a>
* <a href="http://docs.appiaries.com/?p=11075&lang=en">File API</a>
* <a href="http://docs.appiaries.com/?p=11135&lang=en">App User API</a>
* <a href="http://docs.appiaries.com/?p=11255&lang=en">Sequence API</a>

## Appearance

__Notice: the screenshots bellow are the ones from the Android version of this app.__

<table>

<tr>
<td>
<b>Login</b><br />
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_login.png">
</td>
<td>
<b>Register</b><br />
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_register.png">
</td>
<td></td>
</tr>

<tr>
<td colspan="3">
<b>Introduction</b><br />
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_intro.png">
</td>
</tr>

<tr>
<td>
<b>Home</b><br />
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_home.png">
</td>
<td>
<b>Play</b><br />
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_play.png">
</td>
<td>
<b>Sample</b><br />
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_sample.png">
</td>
</tr>

<tr>
<td>
<b>Result</b><br />
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_result.png">
</td>
<td>
<b>Time Ranking</b><br />
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_rank_time.png">
</td>
<td>
<b>First-Come Ranking</b><br />
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_rank_first.png">
</td>
</tr>

</table>


## Server-Side Collections Used

<table>

<tr>
<th>Entity</th>
<th>System Name</th>
<th>Type</th>
<th>Description</th>
<th>Note</th>
</tr>

<tr>
<td>Introduction</td>
<td>Introductions</td>
<td>JSON Collection</td>
<td>Service description texts shown to users after registration. Each object stands for 1 page.</td>
<td></td>
</tr>

<tr>
<td>App Users</td>
<td>(App User)</td>
<td>No collections to be created but App User feature to be used.</td>
<td>Stores App User information using this Puzzle App. In each App User data, also holds attribute data "nickname".</td>
<td></td>
</tr>

<tr>
<td>Stages</td>
<td>Stages</td>
<td>JSON Collection</td>
<td>Stores settings for all stages.</td>
<td></td>
</tr>

<tr>
<td>Images</td>
<td>Images</td>
<td>File Collection</td>
<td>Puzzle image files (the whole image is to be stored instead of divided pieces)</td>
<td></td>
</tr>

<tr>
<td>Time Ranking</td>
<td>TimeRanking</td>
<td>JSON Collection</td>
<td>A type of ranking for the time it took for a user to clear each stage. Shorter the time record, higher on the ranking list.</td>
<td></td>
</tr>

<tr>
<td>First-Come Ranking</td>
<td>FirstComeRanking</td>
<td>JSON Collection</td>
<td>Faster the user clears the given stage, ranked higher on the record.</td>
<td>&#42; Sequence API  to be used.</td>
</tr>

<tr>
<td>First-Come Ranking Sequence</td>
<td>FirstComeRankingSeq</td>
<td>Sequence Collection</td>
<td>Issues a sequence value for each user. Reset when calculated.</td>
<td></td>
</tr>

</table>

If you change the server setting on how you want to split the puzzle image, it displays the game accordingly.  
(on corresponding objects in "Stages" collection)

<table>
<tr>
<td>
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_play.png" style="height:260px;">
<pre class="nums:false">
number_of_horizontal_pieces: 2
number_of_vertical_pieces: 2
</pre>
</td>
<td>
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_play_3x3.png" style="height:260px;">
<pre class="nums:false">
number_of_horizontal_pieces: 3
number_of_vertical_pieces: 3
</pre>
</td>
<td>
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_play_4x4.png" style="height:260px;">
<pre class="nums:false">
number_of_horizontal_pieces: 4
number_of_vertical_pieces: 4
</pre>
</td>
<td>
<img src="http://docs.appiaries.com/wordpress/wp-content/uploads/img/sample_puzzle_shot_play_5x5.png" style="height:260px;">
<pre class="nums:false">
number_of_horizontal_pieces: 5
number_of_vertical_pieces: 5
</pre>
</td>
</tr>
</table>


## Reference

For further details, refer to the official documents on Appiaries.

in English  
http://docs.appiaries.com/?p=14848&lang=en

in Japanese  
http://docs.appiaries.com/?p=14735

Also, Android version available on GitHub.  
https://github.com/appiaries/sample-puzzle-android

Appiaries  
http://www.appiaries.com/
