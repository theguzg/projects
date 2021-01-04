import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { StomachPageComponent } from './stomach-page.component';

describe('StomachPageComponent', () => {
  let component: StomachPageComponent;
  let fixture: ComponentFixture<StomachPageComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ StomachPageComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(StomachPageComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
