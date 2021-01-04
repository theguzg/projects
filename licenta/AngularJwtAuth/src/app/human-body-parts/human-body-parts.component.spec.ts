import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { HumanBodyPartsComponent } from './human-body-parts.component';

describe('HumanBodyPartsComponent', () => {
  let component: HumanBodyPartsComponent;
  let fixture: ComponentFixture<HumanBodyPartsComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ HumanBodyPartsComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(HumanBodyPartsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
