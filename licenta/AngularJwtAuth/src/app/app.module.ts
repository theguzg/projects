//angular imports
import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { AppRoutingModule } from './app-routing.module';
import { HttpClientModule } from '@angular/common/http';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';
import { httpInterceptorProviders } from './auth/auth-interceptor';

//main app components imports
import { AppComponent } from './app.component';
import { LoginComponent } from './login/login.component';
import { UserComponent } from './user/user.component';
import { RegisterComponent } from './register/register.component';
import { HomeComponent } from './home/home.component';
import { AdminComponent } from './admin/admin.component';
import { PmComponent } from './pm/pm.component';
import { HumanBodyModule } from './human-body/human-body.module';

//organs-page imports
import { BrainPageComponent } from './organs-page/brain-page/brain-page.component';
import { BladderPageComponent } from './organs-page/bladder-page/bladder-page.component';
import { LiverPageComponent } from './organs-page/liver-page/liver-page.component';
import { KidneysPageComponent } from './organs-page/kidneys-page/kidneys-page.component';
import { HeartPageComponent } from './organs-page/heart-page/heart-page.component';
import { LargeIntestinesPageComponent } from './organs-page/large-intestines-page/large-intestines-page.component';
import { SmallIntestinesPageComponent } from './organs-page/small-intestines-page/small-intestines-page.component';
import { PancreasPageComponent } from './organs-page/pancreas-page/pancreas-page.component';
import { LungsPageComponent } from './organs-page/lungs-page/lungs-page.component';
import { SplinePageComponent } from './organs-page/spline-page/spline-page.component';
import { StomachPageComponent } from './organs-page/stomach-page/stomach-page.component';

//body imports
import { FemaleBodyComponent } from './human-body-parts/female-body/female-body.component';
import { MaleBodyComponent } from './human-body-parts/male-body/male-body.component';
import { HumanBodyPartsComponent } from './human-body-parts/human-body-parts.component';

//donation imports
import { DonationModule } from './donation/donation.module';

//material imports
import { MatCardModule } from '@angular/material/card';
import { GeneralForumComponent } from './general-forum/general-forum.component';
import { FirstAidComponent } from './first-aid/first-aid.component';
import { EntertainmentComponent } from './entertainment/entertainment.component';
import { BloodDonationComponent } from './blood-donation/blood-donation.component';
import { MatSidenavModule } from '@angular/material/sidenav';
import { MatButtonModule } from '@angular/material/button';
import { MatButtonToggleModule } from '@angular/material/button-toggle';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations'
import { MatSlideToggleModule } from '@angular/material/slide-toggle';
import { MatFormFieldModule } from '@angular/material/form-field';
import { MatSelectModule } from '@angular/material/select';
import { MatInputModule } from '@angular/material';
import { MatTableModule } from '@angular/material/table';
import { MatPaginatorModule } from '@angular/material/paginator';
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
import { MatGridListModule } from '@angular/material/grid-list';
import {MatBadgeModule} from '@angular/material/badge';


@NgModule({
  declarations: [
    AppComponent,
    LoginComponent,
    UserComponent,
    RegisterComponent,
    HomeComponent,
    AdminComponent,
    PmComponent,
    BrainPageComponent,
    BladderPageComponent,
    LiverPageComponent,
    KidneysPageComponent,
    HeartPageComponent,
    LargeIntestinesPageComponent,
    SmallIntestinesPageComponent,
    PancreasPageComponent,
    LungsPageComponent,
    SplinePageComponent,
    StomachPageComponent,
    GeneralForumComponent,
    FirstAidComponent,
    EntertainmentComponent,
    BloodDonationComponent,
    HumanBodyPartsComponent,
    FemaleBodyComponent,
    MaleBodyComponent,
    AnaphylaxisComponent,
    BleedingComponent,
    BurnsComponent,
    ChokingComponent,
    DrowningComponent,
    ElectricShockComponent,
    FractureComponent,
    HeartAttackComponent,
    PoisoningComponent,
    ShockComponent,
    StrokeComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule,
    HttpClientModule,
    HumanBodyModule,
    MatCardModule,
    MatSidenavModule,
    BrowserAnimationsModule,
    MatSlideToggleModule,
    MatButtonModule,
    MatButtonToggleModule,
    MatFormFieldModule,
    MatSelectModule,
    MatInputModule,
    ReactiveFormsModule,
    DonationModule,
    MatTableModule,
    MatPaginatorModule,
    MatGridListModule,
    MatBadgeModule
  ],
  providers: [httpInterceptorProviders],
  bootstrap: [AppComponent]
})
export class AppModule { }
