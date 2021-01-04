import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { KidneysPageComponent } from './kidneys-page.component';

describe('KidneysPageComponent', () => {
  let component: KidneysPageComponent;
  let fixture: ComponentFixture<KidneysPageComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ KidneysPageComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(KidneysPageComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
