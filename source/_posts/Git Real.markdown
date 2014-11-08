---
layout: post
title: "Git Real"
date: 2014-10-31 12:18
comments: true
tags: 
	- git

---

## **Level 1:STAGING & REMOTES** ##
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
## **Level 2:CLONING & BRANCHING** ##
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
git branch -d grooming /*remove it*/
```

###**6. BRANCH SHORTCUTS**###
> The pet shop wants to try selling yet another product line! Let's do this one in a branch in case it gets cancelled like the others. Using a single command, create and check out an `octopus` branch.

```
git checkout -b octopus
```

<br>
## **Level 3:COLLABORATION BASICS** ##
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
![1.pull]()
###**3. FIX CONFLICTS**###
> Git is reporting a conflict with your co-worker's changes in "readme". Just discard his changes, and keep your own (the HEAD).

![2]()
![3]()
![4]()

