import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { BladderPageComponent } from './bladder-page.component';

describe('BladderPageComponent', () => {
  let component: BladderPageComponent;
  let fixture: ComponentFixture<BladderPageComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ BladderPageComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(BladderPageComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
