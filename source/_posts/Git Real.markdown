---
layout: post
title: "Git Real"
date: 2014-11-08 12:18
comments: true
tags: 
	- git

---

#**Level 1:STAGING & REMOTES**#
###**1. UNSTAGED DIFFERENCES**###
> A new file has been added to the site. Run the command to see what all has changed since your last commit.

`git status` will list out which files have changed. If we want to see the actual changes:
```
git diff
```

###**2. STAGE NEW FILE**###
> There it is: `ostrich.html`. Stage it to be committed.

```
git add ostrich.html
```
<!--more-->
###**3. STAGED DIFFERENCES**###
> We've added `ostrich.html` to the staging area, but your co-worker has stopped by and asked to see the new page first. Run a `diff` on the staged changes.

`git diff` is great for seeing **unstaged differences** since last commit, but you need the `--staged` option in order to see staged changes.
```
git diff --staged
```

###**4. UNSTAGE FILES**###
> "Wait," says the co-worker. "They didn't tell you? The client "wants the ostrich section pulled - they couldn't get a license to "sell them." Better unstage `ostrich.html`.
```
git reset HEAD ostrich.html
```

###**5. SKIP STAGING**###
> We've modified the `index.html` file, adding a link to the cats section. Since that file is already tracked, you can just skip staging and commit it with one command.

```
git commit -a -m "index.html adding a link"
```
`-a`: Add changes from all tracked files. Doesn't add new(untracked) files.

###**6. ADD TO COMMIT**###
> Whoops! We forgot to add the `cats.html` page that `index.html` links to, and it should really be `amended` on the same commit. To do this, let's first stage `cats.html`.

```
git add cats.html
```
> Second, let's add `cats.html` to the prior commit and change the commit message in one step. 
```
git commit --amend -m "modified index.html & add cats.html"
```
You don't want to make a new commit, you want to amend the previous one, so what I'm trying to say is: Use the amend option(**add to the last commit**)
Whatever has been staged is added to last commit!

###**7. ROLL BACK COMMIT**###
> Wait, you're getting word that the cats section might be cancelled. **Undo the commit, and put the files back in staging.**

```
git reset --soft HEAD^
```
`soft`: Reset into staging
`HEAD^`: Move to commit before 'HEAD'
Now I can make changes, and re-commit

###**8. DISCARD CHANGES**###
> Forget the whole thing - the client's license to sell cats is suspended during some kind of "investigation". Discard your changes to `cats.html` and `index.html`.

```
git checkout -- cats.html index.html
```
Blow away all changes since last commit.

###**9. REMOVE COMMIT**###
> 1.The next feature is a banner on the main page, saying the pet shop will soon be offering badgers. Add and commit `index.html` in one step, skipping the staging area.
2.Your co-worker is back, looking sheepish. "Never mind the badgers ad. The client's legal department said that was a liability risk." **You'll need to remove the most recent commit, and all its changes.**

```
git commit -am "add index.html"
git reset --hard HEAD^
```
###**10. NEW REMOTE REPOS AND PUSH**###
```
git remote add <name> <address> /*To add new remotes*/
git remote rm <name> /*To remove remotes*/
git remote -v /*show remote repositories*/
git push -u <name> <branch> /*To push to remotes. The -u tells Git to remember the parameters, so that next time we can simply run git push */ 

```

<br>
#**Level 2:CLONING & BRANCHING**#
###**1. CLONE A REPO**###
> The IT department installed an OS update on your workstation - and wiped the hard drive in the process. Clone the Pet Shop repo from `git@example.com:example/petshop.git` so you can resume work.

```
git clone git@example.com:example/petshop.git
```

###**2. LIST REMOTES**###
> Our repo is cloned locally, but how do we check to a list of our remotes? Lets get a list of all our remotes with a verbose output.

```
git remote -v /*show remote repositories*/
```
###**3. CREATE A BRANCH**###
> We need to add a section for the pet grooming salon on the site. You want to isolate this new feature from your other work. Create a new branch named `grooming`.

```
git branch grooming
```

###**4. SWITCH TO BRANCH**###
> You've made the new branch, but your commits are still going to the old one. Switch to the `grooming` branch.

```
git checkout grooming
```

###**5. COMBINE BRANCH**###
>You've finished work on the `grooming` branch and are ready to bring your work back into `master`. First, check out the master branch...
Then,bring your changes from the grooming branch into the ...master branch.

```
git checkout master
git merge grooming
git branch -d grooming /*delete the local branch*/
```

###**6. BRANCH SHORTCUTS**###
> The pet shop wants to try selling yet another product line! Let's do this one in a branch in case it gets cancelled like the others. Using a single command, create and check out an `octopus` branch.

```
git checkout -b octopus
```

<br>
#**Level 3:COLLABORATION BASICS**#
###**1. SEND CHANGES**###
> You've committed some work so now it's time to share! Push it out for your co-workers to see.

```
git push
```
###**2. GET CHANGES**###
> Looks like your co-worker pushed some changes before you did! Your push was rejected. Retrieve the latest changes, and merge them into your branch in one step.

```
git pull
```
![1.pull](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/1.pull.jpg)
###**3. FIX CONFLICTS**###
> Git is reporting a conflict with your co-worker's changes in "readme". Just discard his changes, and keep your own (the HEAD).

![2](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/2.jpg)
![3](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/3.jpg)
![4](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/4.jpg)

<br>
#**Level 4:BRANCHING**#
###**1. PUSH BRANCH**###
> A new kind of pet is for sale at the store! Maybe this one will catch on with the public. You've committed your work to the local `hamsters` branch; now publish this branch in the `origin` repo.

```
git push origin hamsters 
```
Links locak branch to the remote branch(tracking)
###**2. GET REMOTE BRANCH**###
> "git branch -r" does not query the remotes to check for new branches. In order to see a new remote branch you first have to do a fetch or a pull. So retrieve the remote "weasel" branch.

```
git fetch
```
Pull seems like a good choice, but pull will auto merge branches, you only want to update your local branch information, so use fetch instead

###**3. REMOTE BRANCHES**###
> Your co-worker said he wants you to look over a new branch on "origin", but he didn't tell you its name. Get a list of remote branches.

```
git branch -r /*list all remote branches*/
```

###**4. DELETE ON REMOTE**###
> Guess how the product launch went with the weasels? Better delete the "weasel" branch on "origin".

```
git push origin :weasel
```
Use git push to delete the **remote branch**

###**5. BRANCH STATUS**###
>Wait, did you already pull that branch locally? Check for stale branches that are tracking "origin".

```
git remote show origin /* show the state of your branches*/
```
###**6. CLEAN BRANCHES**###
> You still have a stale local branch tracking the now-deleted `origin/weasel`. Clean up your local references.

```
git remote prune origin /* remove deleted remote*/
```
###**7. LIST TAGS**###
> With the weasel threat eliminated, the pet store wants to deploy the site. Let's see, what was the previous version number? Display the tags to find out.Create a tag accordingly

```
git tag  /*list all tags*/
```
###**8. CREATE TAG**###
> Ah, yes, the last release was "v1.3.1". You've added the hamsters, so it would be best to release this as "v1.3.2". Create a tag accordingly.

```
git tag -a v1.3.2 -m "version 0.03"  /*add a new tag*/
```
###**9. SEND TAGS**###
> Push your tag to origin.

```
git push --tags
```
###**10. RETRIEVE TAG**###
> The client is requesting that you roll back to the prior release. (Seriously? What could have gone wrong with the hamsters?) Retrieve the release tagged "v1.3.1".

```
git checkout v1.3.1
```

<br>
#**Level 5:REBASE BELONG TO US**#
###**1. REBASE**###
![7](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/7.jpg) 
![8](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/8.jpg)
> You've made some commits to a feature branch, but you've also committed a hotfix on master that would make a merge messy. Check out the `kennel` branch so you can rebase it on `master`.

```
git checkout kennel
```
> OK, you're on the `kennel` branch. Our goal is to be able to merge `kennel` back into `master` without conflicts or a merge commit. Rebase the current `kennel` branch on `master`.

```
git rebase master
```
> With the rebase complete, `kennel` should merge with `master` cleanly. Switch branches back to `master`.

```
git checkout master
```
> We're on master, and we know the `kennel` will merge cleanly. Go ahead and merge in the `kennel` branch.

```
git merge kennel
```

###**2. REMOTE**###
> Your co-worker has pushed changes to the `master` branch on the `origin` repo. Retrieve it without merging it so we can replay our work on top of it.

```
git fetch
```
![5](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/5.jpg)
> Now that your local repo knows of the latest changes on origin/master, move your master commits after the commits from origin/master.

```
git rebase
```
Use `git rebase` to apply your local commits ahead of those on origin/master.Current branch master is up to date. Success!
![6](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/6.jpg)
###**3. CONFLICT**###
![9](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/9.jpg)
> Your co-worker has pushed before you yet again. Better fetch the changes...

```
git fetch
```
> Now run another rebase to move your commit after the latest fetched one.

```
git rebase
```
> Uh, oh! Looks like the rebase is in conflict this time! Edit `index.html` to fix the conflicting lines. We want to keep our version with `Cats` and `Dogs`.

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <title>Our Cat-alog</title>
  </head>
  <body>
    <nav>
      <ul>
<<<<<<< HEAD   <!--删除 -->
        <li><a href="cat.html">Cats</a></li>
        <li><a href="dog.html">Dogs</a></li>
======= <!--删除 -->
        <li><a href="cat.html">Felines</a></li>   <!--删除 -->
        <li><a href="dog.html">Canines</a></li>   <!--删除 -->
>>>>>>> Add dogs.  <!--删除 -->
      </ul>
    </nav>
  </body>
</html>
```
> Now mark the conflicts in "index.html" as resolved.

```
git add index.html
```
> Now that all conflicts have been resolved and those files added, continue the current rebase in process.

```
git rebase --continue
```
<br>
#**Level 6:HISTORY AND CONFIGURATION**#
> 1.All those e-mail addresses and SHAs are making it hard to see commit messages in your history. Try viewing the log with one commit per line.

```
git log --pretty=oneline
```
> 2.The client called with an urgent question about chew toys, and now you can't remember what you last modified. Bring up a summary of file changes.

```
git diff
```
'git log' will show you your past commits, but it doesn't show you any changes in files, that's what 'git diff' is for.

> 3.You've finished adding elephants to the catalog. You need to write up a change log for the client, and you want to ensure you don't miss anything. Compare the `master` branch to your `elephant` branch to show what's new.
    
```
git diff master elephant
```
> 4.You rebased your latest commit after a commit from your co-worker, but now the page is rendering strangely. To figure out why, get a diff that includes the previous commit, as well as its parent.

```
git diff HEAD~2
```
> 5.Well, you see the changes, but you're not sure what your co-worker was trying to accomplish. Display the diffs along with the log to determine what's going on.

```
git log -p
```
> 6.Wait, what? You don't understand these lines in `index.html`. You'd better find out who committed them, so you can ask them what they're supposed to do.

```
git blame index.html
```
Use `git blame` to see the annotated source, so you can figure out who made all these changes


###**EXCLUDING**###
![10](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/10.jpg)
![11](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/11.jpg)
###**REMOVING**###
![12](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/12.jpg)
![13](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/13.jpg)
###**CONFIG**###
![14](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/14.jpg)
###**ALIASES**###
![15](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/15.jpg)
![16](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/git/16.jpg)