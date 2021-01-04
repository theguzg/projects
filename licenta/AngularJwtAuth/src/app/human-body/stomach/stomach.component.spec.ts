import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { StomachComponent } from './stomach.component';

describe('StomachComponent', () => {
  let component: StomachComponent;
  let fixture: ComponentFixture<StomachComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ StomachComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(StomachComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
