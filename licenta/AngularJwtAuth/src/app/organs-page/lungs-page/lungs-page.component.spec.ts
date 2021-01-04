import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { LungsPageComponent } from './lungs-page.component';

describe('LungsPageComponent', () => {
  let component: LungsPageComponent;
  let fixture: ComponentFixture<LungsPageComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ LungsPageComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(LungsPageComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
