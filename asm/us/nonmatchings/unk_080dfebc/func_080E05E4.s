.syntax unified
	.align 2, 0
	.global func_080E05E4
	.thumb
	.thumb_func
	.type func_080E05E4, %function
func_080E05E4: @ 080E05E4
	push {r4, lr}
	ldr r4, _080E061C @ =0x0203C7AC
	ldr r0, [r4, #0x00]
	ldr r1, _080E0620 @ =0x0203C590
	ldrb r1, [r1, #0x06]
	bl func_080DF6D0
	ldr r0, [r4, #0x00]
	ldrb r0, [r0, #0x0D]
	cmp r0, #0x05
	bne _080E0608
	ldr r0, _080E0624 @ =0x02039BA0
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x70]
	movs r1, #0x80
	lsls r1, r1, #0x02
	orrs r0, r1
	str r0, [r2, #0x70]
_080E0608:
	ldr r0, _080E0624 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0x78
	ldr r1, _080E0628 @ =0x09EF6B00
	movs r2, #0x00
	bl TaskCreate
	pop {r4}
	pop {r0}
	bx r0
_080E061C: .4byte 0x0203C7AC
_080E0620: .4byte 0x0203C590
_080E0624: .4byte 0x02039BA0
_080E0628: .4byte 0x09EF6B00
.syntax divided
