.syntax unified
	.align 2, 0
	.global func_080DF964
	.thumb
	.thumb_func
	.type func_080DF964, %function
func_080DF964: @ 080DF964
	push {r4, lr}
	movs r4, #0x00
	b _080DF97E
_080DF96A:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl func_080E54B8
	ldrb r0, [r0, #0x00]
	bl func_080DEDD8
	bl func_080DEBD8
	adds r4, #0x01
_080DF97E:
	ldr r0, _080DF98C @ =0x0203C590
	ldrb r0, [r0, #0x05]
	cmp r4, r0
	blt _080DF96A
	pop {r4}
	pop {r0}
	bx r0
_080DF98C: .4byte 0x0203C590
.syntax divided
