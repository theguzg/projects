import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { SplinePageComponent } from './spline-page.component';

describe('SplinePageComponent', () => {
  let component: SplinePageComponent;
  let fixture: ComponentFixture<SplinePageComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ SplinePageComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(SplinePageComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
