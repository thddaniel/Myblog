---
layout: post
title: "Git Real 2"
date: 2014-11-09 12:18
comments: true
tags: 
	- git

---

![0](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/0.jpg)
#**INTERACTIVE REBASE**#
##**REBASE RECAP**###
> So you've been working on your feature branch for a couple days and you realize you need to bring commits back in from master. Now you could just merge in the branch but that would create an ugly merge commit. Use rebase to bring those changes into your branch without the merge commit.
<!--more-->
```
git rebase master
```

##**INTERACTIVE REBASE**###
> You're getting ready to merge in your feature branch, but first you want to clean up your commits a bit. Go ahead and use interactive rebase to edit your last 4 commits.

```
git rebase -i HEAD~4  /*alter commits in the same branch*/
```
We want to re-order these four commits.


##**COMMIT ORDERING**###
> You notice a critical error on your part. The commit where you wrote tests comes after the commit where you made the actual changes. Let's swap these 2 commits so that it looks like you wrote the tests first. Swap the 'Add tests' commit so that it comes before the 'Implement poodles' commit.

`editor:`
```
pick b3f1649 Add unicorn
pick f239187 Implement poodles  //change to pick 4b65a5a Add tests 
pick 4b65a5a Add tests          //change to pick f239187 Implement poodles
pick c3f863f Added a title to the homepage
```
Swap the order,save and close the editor.Commits get replayed in new order.

##**REWORDING A COMMIT**###
> 1.As you're editing your commits, you notice that the commit that says 'Add tests' is a little vague, maybe you should change it to something more specific. Use the reword command to change the message of this commit.

`editor:`
```
pick b3f1649 Add unicorn
pick 4b65a5a Add tests // reword 4b65a5a Add tests
pick f239187 Implement poodles
pick c3f863f Added a title to the homepage
```
Commands:
p, pick = use commit
r, reword = use commit, but edit the commit message
e, edit = use commit, but stop for amending
s, squash = use commit, but meld into previous commit
f, fixup = like "squash", but discard this commit's log message
x, exec = run command (the rest of the line) using shell

> 2.After setting the `reword` command in the interactive rebase editor **another editor window has opened up**. This is where you actually change the commit message. Go ahead and change the commit message to: `Add tests for poodles` to be more descriptive.

`editor:`
```
Add tests //Add tests for poodles
```
##**SPLIT COMMITS**###
> 1.You remember that the 'Add unicorn' commit also contains the testing changes. Since we have separate commits for adding tests for poodles it makes sense to split out the test changes into a separate commit. Tell git to stop at this commit so we can reorganize it a bit.

`editor:`
```
pick b3f1649 Add unicorn   //edit b3f1649 Add unicorn
pick 4b65a5a Added tests for poodles
pick f239187 Implement poodles
pick c3f863f Added a title to the homepage
```
> 2.After saving the interactive rebase text file, git has stopped at the 'Add unicorn' commit. The first thing we need to do is to reset back to the previous commit, so the changes in the most recent commit are back in the file and unstaged.

```
git reset HEAD^ 
```

> 3.Great! You've already re-committed the changes needed in 2 different commits. All that's left to do is to resume the rebase with the continue option.

```
git rebase --continue
```
One commit is now two.

##**SQUASHING COMMITS**###
> 1.You noticed another bug with those pesky poodles, so you've gone ahead and fixed it, making another commit in the process. Now you have 2 commits that both affect the poodles page. You should squash them into one commit to simplify your git logs.

`editor:`
```
pick b3f1649 Add unicorn
pick 4b65a5a Add tests
pick f239187 Implement poodles
pick c3f863f Add title to poodle page //squash c3f863f Add title to poodle page
```

> 2.After designating a commit to be squashed, another editor pops up enabling you to set a commit message for the resulting commit. Go ahead and set to: `squashed some poodles`.

`editor:`

```
//This is a combination of 2 commits.
//The first commit's message is:

Implement poodles //注释掉

//This is the 2nd commit message:

Add title to poodle page //注释掉

//合并成你想的名字：
squashed some poodles
```

The content of two commits is replayed, but only one commit is made.
<br>
#**STASHING**#
##**GIT STASH**###
> You're not quite ready to commit what you're working on, but need to make a quick fix to master. Fear not, just stash your current changes so you can switch to master quick.

```
git stash save  // = git stash
```

##**GIT STASH LIST**###
> You just finished making those quick changes to master. You're now ready to resume your work on the feature you had started on before you had to fix master. Let's first list all the stashes to make sure we get the right one.

```
git stash list   //stash names are shown in the list 
```

##**GIT STASH APPLY**###
> Great! As you can see, your stash is in the stash list. Let's apply the stash so you can get back to work.

```
git stash apply stash@{0} // = git stash apply
```
`stash@{0}` is the default.
stash has been applied but it's still here.
##**GIT STASH DROP**###
> Ok, so now that you have all your stashed changes back, let's clean up the stash list. There's only one stash; go ahead and drop it.

```
git stash drop  //Delete stash@{0} from list
git stash clear //Clear all of them at once
```
##**CONFLICTS**###
> 1.You came back from master and resumed working on your feature, when you realize that you forgot to apply your saved stash. Go ahead and apply it now.

```
git stash apply
```

> 2.Uh oh! There was a conflict when trying to apply your previous stash. It's no problem, you were just trying things anyway. Go ahead and do a hard reset back to the last commit.

```
git reset --hard HEAD
git stash apply
```

##**GIT STASH POP**###
> Now that you have the file reset, use the `pop` command to **apply and delete the stash at the same time**. 

```
git stash pop 
```

##**KEEPING THE INDEX**###
> You need to swap branches again, but this time some of your changes are ready to be committed. Stash all the unstaged changes, but leave the staged changes intact so they can be committed afterwards.

```
git stash save --keep-index //cause the staging area not to be stashed
```

##**INCLUDE UNTRACKED**###
> Wow, there are so many small fixes on master today! You really need to stash some more changes, but it doesn't seem to be working on these untracked files you just created. Try using the `--include-untracked` option to stash all those new files.

```
git stash save --include-untracked //cause untracked files to be stashed,too
```

##**LIST OPTIONS**###
> You've been stashing stuff all day since you keep having to make small quick fixes to master. Now you have a bunch of stashed changes and you're not sure which one you need to apply. You could look through them all one by one, or you could use the `--stat` option to list information about each stash. Give that a try.
```
git stash list --stat //summarizes file changes
```
##**STASH DETAILS**###
> You now have a list of stashes that are showing you more information, and you think you may have spotted the stash that you need. Take a more detailed look at the stash@{2} stash with the `--patch` option.

```
git stash show stash@{2} --patch //show file differents
```
##**STASH MESSAGE**###
> You're halfway through a large feature. Your team has decided that they want you to deploy what you have so far, but you have a smaller unfinished feature that isn't ready to be committed yet. Go ahead and stash your current changes with the **message `Added groom method`**, so you know which stash has your changes.

```
git stash save "Added groom method" 
```
##**STASH BRANCHING**###
> Now that you've deployed the main part of your feature, you need to finish up what is left. Create a new branch named `poodle` and apply your most current stash all in one command.

```
git stash branch poodle stash@{0}
```
`git stash branch`checks a new branch out automatically, and drops the stash automatically.
<br>
#**PURGING HISTORY**#
![17](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/17.jpg)
##**REPO COPY**###
> Now you've done it. You accidentally put the company's master password into one of your files. You're beginning to panic because you know that it's pretty hard to delete something forever in git. That's what you really need to do, though, or you're in big trouble. You're going to need to purge the history. First, though, make a copy of your repo in case you mess it up. Make a copy of the `poodles` repository, and name it whatever you want.

```
git clone poodles poodles_copy
```

##**TREE FILTER**###
> Luckily for you, the password you accidentally committed was in the `master_password.txt` file. Use the `filter-branch` command and remove this file from all of your commits.

```
//git filter-branch --tree-filter <command> ... 
//specify any shell commend
git filter-branch --tree-filter 'rm -f master_password.txt'
```
`...`: 

- `--all` option filter all commits in all branches.
- `HEAD` filter only current branch.

Git will check each commit out into **working directory**, run your command, and re-commit.

##**INDEX FILTER**###
> This repository is so large, using `--tree-filter` is going to take all day. Use `--index-filter` to remove `master_password.txt` instead. Remember, `--index-filte`r will need a command that works on the staging area, which is going to be some sort of git command.

```
//git filter-branch --index-filter <command> ...
//command must operate on staging area.
git filter-branch --index-filter 'git rm --cached --ignore-unmatch master_password.txt'
```
It operates on **staging area**. 
`--ignore-unmatch`: succeeds even if file isn't present.
Git will run your command against each commit, but without checking it out first(so it's faster).
##**FORCE**###
> You just realized that you also have a `master_username.txt` file that should probably be removed too, just to be safe. Use either technique you have learned to remove this file. Don't forget, you have a history backup from the first time you used `filter-branch`. Use the correct option to force git to overwrite it.

After you run filter-branch, Git leaves a backup of your tree in the ".git" directory.By default, you can't run filter-branch again because it won't overwrite the backup.You can force it with the -f option.
```
git filter-branch -f --tree-filter 'git rm --cached --ignore-unmatch master_username.txt'
```

##**PRUNING**###
> Great! Now we're getting somewhere. There is one more problem though, you realize that some of the commits don't contain anything anymore, since you removed the password file that they referenced. You should probably use the `--prune-empty` option do something to clean these out.

```
git filter-branch -f --prune-empty
```
`--prune-empty` option drops commits that don't alter any files.

<br>
#**WORKING TOGETHER**#

##**LINE ENDINGS**###
> 1.Your company just hired a new developer who works on a Windows computer, and you notice that some files seem to be missing line separators. You realize that the Windows machine is saving files with a different line separator character than the Unix stations. Here on your Unix machine, set your 'git config' variable to convert line endings to the Unix way on commit.

![18](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/18.jpg)

```
git config --global core.autocrlf input
```

> 2.Because you're a nice person, you decide to go help the new developer convert line endings to work on his windows computer. Set the `git config` variable to convert line endings from Unix to Windows formats on checkout.

```
git config --global core.autocrlf true
```
![19](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/19.jpg)
> 3.After helping a 3rd Windows developer set up their workstation, you've decided enough is enough. It's time to add a `.gitattributes` file to handle all these line ending problems. Finish adding the options to the `*.bat` and `*.sh files`. Remember, `*.bat` is a windows file, while `*.sh` is a unix file.

![20](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/20.jpg)

`text=auto` Choose conversion automatically
`text` Treat files as text -convert to OS's line endings back to LF on commit
`text eol = crlf` `text eol = lf` Convert to specified format on checkout back to LF commit
`binary` Treat files as binary - do no conversion

![21](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/21.jpg)

##**CHERRY PICKING**###
![22](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/22.jpg)
> You were working on a new feature for the Unicorn class, when you happened to find a fix for a bug that was causing Unicorns to stop sparkling on occasion. You really want this commit in master ASAP. Cherry-pick the commit with a sha of `3fbd473` to the master branch.

```
git cherry-pick 3fbd473 //specify commit you want
```
We copied a single commit a single commit to the current branch
##**EDIT A CHERRY PICK**###

> You've realized that this commit `3fbd473`, which you need to cherry pick, has a rather vague message. Do another cherry-pick, but edit the commit message this time.

```
git cherry-pick --edit 3fbd473
```
Then enter your message, save ,and quit.


##**CHERRY PICK SQUASH**###
> 1.You've fixed another bug that was causing the unicorn horn to be blunt instead of nice and sharp, but you had to make an extra commit to remove some debugging code. We want to convert these two commits to a single commit on the master branch. Cherry-pick commits `b447335`" and `b59d285`, without committing them to the current branch.
```
git cherry-pick --no-commit b447335 b59d285
```
`--no-commit` pulls in changes and stages them, but doesn't commit

> 2.The changes from both cherry picked commits are now on master, and all that's left to do is to commit these changes. (Don't forget the commit message!)

```
git commit -m "add both"
```
##**TRACKING CHERRY PICKS**###
> There has been a lot of cherry picking lately, so the decision has been made to keep track of where these commits are coming from. Cherry pick the "bug fix" commit with a sha of `bdf9578`. Use the option which keeps a record of where the commit was cherry picked.

```
git cherry-pick -x bdf9578
```
`-x` adds source SHA to commit message.
Only useful with public branches; don't use for local branches

##**SIGNING OFF**###
> You've decided that it is probably a good idea to put your name on these commits you're cherry picking. Go ahead and get started by cherry picking the commit with a sha of `bdf9578`. Don't forget to use the option which will sign off on the cherry pick!

```
git cherry-pick --signoff bdf9578
```
`--signoff` adds current user's name to commit message.

<br>
#**SUBMODULES**#
##**BAD WAYS TO SHARE LIBRARIES**###
![23](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/23.jpg)
##**GIT SUBMODULES**###
![24](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/24.jpg)
##**SUBMODULE**###
> You're in the process of putting together two websites. One is for the Mythical Wildlife Fund: `MWF.com`. The other site is an adoption site for stray unicorns called `unicornrescues.com`. Both sites will share code for a JavaScript image gallery along with the associated css. Let's get started by adding a submodule containing the JavaScript at `"git@petstore.com:gallery_js.git"`.

```
git submodule add git@petstore.com:gallery_js.git
```

##**STAGING A SUBMODULE**###
> All that's left to do is to commit your submodule so that other collaborators can use it. Using a single git command, stage the current changes to `.gitmodules` and `gallery_js`.

```
git add -A
```

##**COMMITTING A SUBMODULE**###
> Great! Now go ahead and commit the submodule. Don't forget the commit message!

```
git commit -m "Add submodule"
```

##**INIT SUBMODULE**###
> You're helping a co worker get set up to work on unicornrescues.com. You've already cloned the repo. Next, initialize the submodules so they download their own contents.

```
git submodule init
```

##**UPDATE SUBMODULES**###
> Now that you have the submodules initialized, you need to check for updates and make sure they have the correct commits checked out. Run the submodule command that does this.

```
git submodule update
```

##**DETACHED HEAD**###
> You've just committed a few changes to the `gallery_css` submodule. When you go to push, you realize that you're in a detached head state. Don't panic, though! We can fix it. Let's start out by creating a new branch with your most recent commit: "a7eded4". Name the branch `temp_changes`.

```
git branch temp_changes a7eded4
```

##**BRANCH MERGE**###
> Your seemingly lost changes now reside on the `temp_changes` branch. Go ahead and merge the `temp_changes` branch back into master.

```
git merge temp_changes
```

##**PUSH CHECK**###
> After finishing up a bunch of changes, you want to push them up to the remote so you can share it with your other co-workers that are working on the project. Since you're using submodules, you should make sure to use the option which checks whether you have un-pushed submodules.

```
git push --recurse-submodules=check
```

##**ON DEMAND PUSH**###
> We need to push submodule changes again. But this time, instead of going into the submodule to push it, just use the `on-demand` option for the `--recurse-submodules` option. This way submodules that need it will be pushed automatically.

```
git push --recurse-submodules=on-demand
```

##**ON DEMAND ALIAS**###
> Wouldn't it be nice if you didn't have to type that long line out every time you wanted to push this project? Let's make the command easier to use. Create an alias which will run the git push `--recurse-submodules=on-demand` command. Name the alias anything you want.

```
git config alias.pushall "push --recurse-submodules=on-demand"
git pushall
```

<br>
#**REFLOG**#
##**THE MISTAKE**###
> You decided that unicorns should leave a rainbow trail when they jump. You made the upgrade, and committed the changes. There is a problem, though: this change caused a bug which prevents the unicorns from jumping at all. You panic! Hurry, do a "hard reset" back to the commit before the rainbow jumping was added: `"ab27026"`.
$ git log --oneline
8791492 Rainbow trail when jumping.
ab27026 Implement unicorn jumping.
.....

```
git reset --hard ab27026
```

##**REFLOG**###
> You realize after the fact that maybe the hard reset was a bit overkill. You still wanted your code used to add rainbow jumps. It's a good thing git never really gets rid of commits. Let's look at the reflog to see if there is anything we can do.

![25](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/25.jpg)
```
git reflog //查看
```
![26](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/26.jpg)

##**RESETTING THE REFLOG**###
> Great, we can see that there is a log of the reset! Take note of the reflog entry right before your earlier reset. Then do a "hard reset" to that commit to get your work back.

```
git reset --hard 8791492 // git reset --hard HEAD@{1}
```

##**DELETING A BRANCH**###
> You decide to clean house a bit. You know that all branches have either been merged or abandoned, so you're going to delete them to keep a tidy repository. Go ahead and get started by deleting the `fluffy_poodle` branch.

```
git branch -D fluffy_poodle
```

##**WALKING REFLOGS**###
> Then you realize that you needed the styles menu from that `fluffy_poodle` branch you just deleted. Good thing git never really gets rid of anything. List all commits in the reflog by using the `--walk-reflogs` option of git log.

![27](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/27.jpg)

```
git log --walk-reflogs //查看
```

##**BRANCH RECOVERY**###
> Now that you know what the last commit was on the deleted branch, you can create a new branch and attach the commit to it. Create a new branch named `fluffy_poodle` using the most recent commit from the deleted branch.
$ git log --walk-reflogs --oneline
b8ec575 HEAD@{0}: checkout: moving from fluffy_poodle to master
aaafb5e HEAD@{1}: commit: Fluff poodle.
....

```
git branch fluffy_poodle HEAD@{1} //git branch fluffy_poodle aaafb5e
```