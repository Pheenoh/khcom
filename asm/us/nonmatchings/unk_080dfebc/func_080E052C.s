.syntax unified
	.align 2, 0
	.global func_080E052C
	.thumb
	.thumb_func
	.type func_080E052C, %function
func_080E052C: @ 080E052C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080E0548
	ldr r1, _080E0550 @ =0x02039BB0
	movs r0, #0xFF
	strb r0, [r1, #0x0F]
	ldr r0, _080E0554 @ =0x0203DB10
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r1, #0xFF
	bl func_08120EF8
_080E0548:
	bl func_080E04EC
	pop {r0}
	bx r0
_080E0550: .4byte 0x02039BB0
_080E0554: .4byte 0x0203DB10
.syntax divided
