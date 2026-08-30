.syntax unified
	.align 2, 0
	.global func_080DEBD8
	.thumb
	.thumb_func
	.type func_080DEBD8, %function
func_080DEBD8: @ 080DEBD8
	push {lr}
	ldrb r1, [r0, #0x00]
	cmp r1, #0x01
	beq _080DEBE4
	cmp r1, #0x04
	bne _080DEBFC
_080DEBE4:
	ldrb r0, [r0, #0x02]
	bl func_080DEE18
	movs r2, #0x00
	strb r2, [r0, #0x0A]
	movs r1, #0x1A
	strb r1, [r0, #0x08]
	strb r2, [r0, #0x09]
	ldrh r2, [r0, #0x00]
	movs r1, #0x08
	orrs r1, r2
	strh r1, [r0, #0x00]
_080DEBFC:
	pop {r0}
	bx r0
.syntax divided
