.syntax unified
	.align 2, 0
	.global func_0807A620
	.thumb
	.thumb_func
	.type func_0807A620, %function
func_0807A620: @ 0807A620
	push {r4, r5, lr}
	adds r5, r0, #0x0
	movs r4, #0x00
_0807A626:
	lsls r0, r4, #0x04
	adds r0, #0x54
	adds r0, r5, r0
	bl func_08000C8C
	adds r1, r0, #0x0
	adds r4, #0x01
	cmp r1, #0x00
	beq _0807A65A
_0807A638:
	adds r2, r1, #0x0
	adds r2, #0xA1
	ldrb r0, [r2, #0x00]
	subs r0, #0x05
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bls _0807A64C
	movs r0, #0x07
	strb r0, [r2, #0x00]
_0807A64C:
	adds r0, r1, #0x0
	adds r0, #0x64
	bl func_08000CD4
	adds r1, r0, #0x0
	cmp r1, #0x00
	bne _0807A638
_0807A65A:
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x03
	bls _0807A626
	ldr r0, _0807A680 @ =0x02034A98
	ldr r2, [r0, #0x00]
	ldr r1, [r2, #0x78]
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r0, r1
	cmp r0, #0x00
	beq _0807A67A
	movs r0, #0x80
	lsls r0, r0, #0x07
	orrs r1, r0
	str r1, [r2, #0x78]
_0807A67A:
	pop {r4, r5}
	pop {r0}
	bx r0
_0807A680: .4byte 0x02034A98
.syntax divided
