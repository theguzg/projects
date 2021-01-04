import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { KidneysComponent } from './kidneys.component';

describe('KidneysComponent', () => {
  let component: KidneysComponent;
  let fixture: ComponentFixture<KidneysComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ KidneysComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(KidneysComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
