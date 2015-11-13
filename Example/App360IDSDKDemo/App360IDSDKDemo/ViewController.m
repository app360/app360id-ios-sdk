//
//  ViewController.m
//  App360IDSDKDemo
//
//  Created by Tuan Tran Manh on 4/8/15.
//  Copyright (c) 2015 Mwork. All rights reserved.
//

#import "ViewController.h"

#import <App360IDSDK/App360IDSDK.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onLoginButtonTapped:(id)sender
{
    [App360IDSDK loginWithScope:k360IDScopeBasic shouldDisplayUI:YES fromController:self block:^(App360User *user, NSError *error) {
        NSLog(@"Logged user: %@ -> %@", user.userId, user.displayName);
    }];
}

- (IBAction)onLogoutButtonTapped:(id)sender
{
    [App360IDSDK logout];
}

@end
