import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { HeartPageComponent } from './heart-page.component';

describe('HeartPageComponent', () => {
  let component: HeartPageComponent;
  let fixture: ComponentFixture<HeartPageComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ HeartPageComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(HeartPageComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
