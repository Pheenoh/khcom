.syntax unified
	.align 2, 0
	.global func_080126E4
	.thumb
	.thumb_func
	.type func_080126E4, %function
func_080126E4: @ 080126E4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0x0
	bl func_08006B74
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08012708
	ldr r0, _08012704 @ =0x02034928
	ldr r0, [r0, #0x00]
	adds r0, #0x38
	strb r4, [r0, #0x00]
	movs r0, #0x00
	b _08012722
	.byte 0x00, 0x00
_08012704: .4byte 0x02034928
_08012708:
	ldr r0, _0801271C @ =0x02034928
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x38
	ldrb r0, [r1, #0x00]
	cmp r0, r5
	bcc _08012720
	strb r5, [r1, #0x00]
	movs r0, #0x00
	b _08012722
_0801271C: .4byte 0x02034928
_08012720:
	movs r0, #0x01
_08012722:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
