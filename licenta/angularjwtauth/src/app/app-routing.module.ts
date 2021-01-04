import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';

import { RegisterComponent } from './register/register.component';
import { LoginComponent } from './login/login.component';
import { HomeComponent } from './home/home.component';
import { UserComponent } from './user/user.component';
import { PmComponent } from './pm/pm.component';
import { AdminComponent } from './admin/admin.component';
import { BrainPageComponent } from './organs-page/brain-page/brain-page.component';
import { HeartPageComponent } from './organs-page/heart-page/heart-page.component';
import { BladderPageComponent } from './organs-page/bladder-page/bladder-page.component';
import { KidneysPageComponent } from './organs-page/kidneys-page/kidneys-page.component';
import { LargeIntestinesPageComponent } from './organs-page/large-intestines-page/large-intestines-page.component';
import { SmallIntestinesPageComponent } from './organs-page/small-intestines-page/small-intestines-page.component';
import { LiverPageComponent } from './organs-page/liver-page/liver-page.component';
import { LungsPageComponent } from './organs-page/lungs-page/lungs-page.component';
import { PancreasPageComponent } from './organs-page/pancreas-page/pancreas-page.component';
import { SplinePageComponent } from './organs-page/spline-page/spline-page.component';
import { StomachPageComponent } from './organs-page/stomach-page/stomach-page.component';
import { BloodDonationComponent } from './blood-donation/blood-donation.component';
import { GeneralForumComponent } from './general-forum/general-forum.component';
import { FirstAidComponent } from './first-aid/first-aid.component';
import { EntertainmentComponent } from './entertainment/entertainment.component';
import { HumanBodyPartsComponent } from './human-body-parts/human-body-parts.component';
import { DonationComponent } from './donation/donation.component';
import { DonationListComponent } from './donation/donation-list/donation-list.component';
import { AnaphylaxisComponent } from './first-aid/anaphylaxis/anaphylaxis.component';
import { BleedingComponent } from './first-aid/bleeding/bleeding.component';
import { BurnsComponent } from './first-aid/burns/burns.component';
import { ChokingComponent } from './first-aid/choking/choking.component';
import { DrowningComponent } from './first-aid/drowning/drowning.component';
import { ElectricShockComponent } from './first-aid/electric-shock/electric-shock.component';
import { FractureComponent } from './first-aid/fracture/fracture.component';
import { HeartAttackComponent } from './first-aid/heart-attack/heart-attack.component';
import { PoisoningComponent } from './first-aid/poisoning/poisoning.component';
import { ShockComponent } from './first-aid/shock/shock.component';
import { StrokeComponent } from './first-aid/stroke/stroke.component';

const routes: Routes = [
    {
        path: 'home',
        component: HomeComponent
    },
    {
        path: 'user',
        component: UserComponent
    },
    {
        path: 'pm',
        component: PmComponent
    },
    {
        path: 'admin',
        component: AdminComponent
    },
    {
        path: 'auth/login',
        component: LoginComponent
    },
    {
        path: 'signup',
        component: RegisterComponent
    },
    {
        path: 'brain_page',
        component: BrainPageComponent
    },
    {
        path: 'heart_page',
        component: HeartPageComponent
    },
    {
        path: 'bladder_page',
        component: BladderPageComponent
    },
    {
        path: 'kidneys_page',
        component: KidneysPageComponent
    },
    {
        path: 'large_intestines_page',
        component: LargeIntestinesPageComponent
    },
    {
        path: 'small_intestines_page',
        component: SmallIntestinesPageComponent
    },
    {
        path: 'liver_page',
        component: LiverPageComponent
    },
    {
        path: 'lungs_page',
        component: LungsPageComponent
    },
    {
        path: 'pancreas_page',
        component: PancreasPageComponent
    },
    {
        path: 'spline_page',
        component: SplinePageComponent
    },
    {
        path: 'stomach_page',
        component: StomachPageComponent
    },
    {
        path: 'blood_donation',
        component: BloodDonationComponent
    },
    {
        path: 'donation',
        component: DonationComponent
    },
    {
        path: 'donationList',
        component: DonationListComponent
    },
    {
        path: 'forum',
        component: GeneralForumComponent
    },
    {
        path: 'first_aid', component: FirstAidComponent, children: [
            { path: 'anaphylaxis', component: AnaphylaxisComponent },
            { path: 'bleeding', component: BleedingComponent },
            { path: 'burns', component: BurnsComponent },
            { path: 'choking', component: ChokingComponent },
            { path: 'drowning', component: DrowningComponent },
            { path: 'electric_shock', component: ElectricShockComponent },
            { path: 'fracture', component: FractureComponent },
            { path: 'heart_attack', component: HeartAttackComponent },
            { path: 'poisoning', component: PoisoningComponent },
            { path: 'shock', component: ShockComponent },
            { path: 'stroke', component: StrokeComponent },
            { path: '', redirectTo: 'first_aid', pathMatch: 'full' }
        ]
    },
    // {
    //     path: 'first_aid',
    //     component: FirstAidComponent
    // },
    // {
    //     path: 'first_aid/anaphylaxis',
    //     component: AnaphylaxisComponent
    // },
    // {
    //     path: 'first_aid/bleeding',
    //     component: BleedingComponent
    // },
    {
        path: 'entertainment',
        component: EntertainmentComponent
    },
    {
        path: 'human_body_parts',
        component: HumanBodyPartsComponent
    },
    {
        path: '',
        redirectTo: 'home',
        pathMatch: 'full'
    }
];

@NgModule({
    imports: [RouterModule.forRoot(routes)],
    exports: [RouterModule]
})
export class AppRoutingModule { }
