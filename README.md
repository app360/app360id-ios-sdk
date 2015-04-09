#Introduction

App360ID SDK helps you build engaging social apps and get more installs

The App360ID iOS SDK supports iOS version 6.0 and above.

#Requirements

##Development Environment

| App360IDSDK Version | Minimum iOS Target | 				Notes 			|
|:-----------------:|:------------------:|:----------------------------:|
|1.0.0|6.0|Xcode 6.1 is required. Support armv7, armv7s and arm64 architectures (+ i386 for the simulator)|

###Library compatibility

The App360ID iOS SDK supports all iOS 6.0 and above versions. It compiles against the armv7, armv7s and arm64 architectures (+ i386 for the simulator).

###Xcode

We are using Xcode 6.2 to create our demo projects. You may encounter some errors if you are using a lower version of Xcode. That's why we recommend you work on the latest (non-beta) available version.

#Getting started with Demo project

Firstly, clone or download this repository to your machine.

- `git clone https://github.com/app360/app360id-ios-sdk.git`
- Or, download from https://github.com/app360/app360id-ios-sdk/releases

Open AppDelegate.m inside demo project, find `initializeWithApplicationId` line and replace the placeholders with your application credentials.

Run the project. The app demonstrates capability of App360ID SDK.

#Setup your project

##Application Id & Client key

To using any function of App360SDK, you need to configure application id and secret. SDK uses this pair of key to authorize your app (game) with SDK's server. To retrieve application ID and client secret, register your application on https://developers.app360.vn/; your application ID and secret is available in application details page, Information tab.

![App credentials](http://i.imgur.com/4xZ8fYc.png)

##Redirect

To handle login flow, the project's directory should contain a properties file named `app360.plist`. The file should contain `redirect_uri`. `redirect_uri` can be configure on App360 Developer. You can find it in application detail page, Information tab, OAuth2 section (OAuth2 Redirect URIs)

##Import the library into your project

The sample project displays the simplest way to install the SDK inside your app: Dragging & dropping the SDK into your own project.

To get started, drag `App360IDSDK.framework` and `MWNetworking.framework` onto **Embedded Binaries** section :

![Imgur](http://i.imgur.com/y1cY5gD.png)

Then, drag and drop SDK's bundle into your project

![Imgur](http://i.imgur.com/YoSMVNE.png)

Choose '**Create groups**' and select '**Copy items if needed**' to copy sdk to your project folder

![Imgur](http://i.imgur.com/MOTKyPG.png)

#Integrate SDK into your project

##Initialize

To initialize App360ID SDK, in AppDelegate.m, call method

```objective-c
[App360IDSDK initializeWithAppId:@"your-app-id" appSecret:@"your-app-secret"];
```

Don't forget import SDK's header

```objective-c
#import <App360IDSDK/App360IDSDK.h>
```

##Login

To login, call login method


```objective-c
[App360IDSDK loginWithScope:k360IDScopeBasic shouldDisplayUI:NO block:^(App360User *user, NSError *error) {
    if (user) {
        //login and get user info success
    } else if (error) {
        //error => See error object for more information
    }
}];
```

Note: Set `shouldDisplayUI` to `NO` to tell SDK not show login form, just open last session if posible. If `shouldDisplayUI` to `YES` and there's no saved session info, SDK will show login form for user to login.

##Logout

To logout user, just call

```objective-c
[App360IDSDK logout];
```


#Release Notes

##Version 1.0.0

**Release date**: 09 Apr 2015

 - Initial version

#Known Issues

There's no known issues for now

#FAQ

**What is a application id and client key?**

They are a pair of key, used to authorize your app (game) with SDK's server.

**How can i get my application id and client key?**

1. Goto https://developers.app360.vn
2. Login if you already have an account or register a new one
3. Open your application in App360 dashboard, select Information tab
4. All key you need will be there

**How much does the App360ID iOS SDK add to my application size?**

The latest version of the SDK weighs less than 1MB. But this isn't the size which will be added to your archive when submitted to iTunes.
Based on several tests, it should adds below 1MB depending of the size of your application.
The bigger your app is, the less the App360ID iOS SDK will have an impact on the final size.

#Support
Please contact [us](mailto:support@app360.vn) for general inquiries.

##For a technical issue
In case you have a technical issue, you can reach [our technical support team](mailto:support@app360.vn).
Please provide the following information when you reach out, it'll allow us to help you much more quickly.

 - **The library version** you're using. You can get the precise number by
   printing the result of the `[App360IDSDK getSDKVersion];` method.
 - **The platform** used to produce the problem (device model or simulator),
   and the iOS version.
 - **The steps** to reproduce the problem.
 - If possible, **some pieces of code**, or even a project.

> For more information, please go to https://developers.app360.vn.