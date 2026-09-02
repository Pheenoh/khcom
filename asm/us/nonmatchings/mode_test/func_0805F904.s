.syntax unified
	.align 2, 0
	.global func_0805F904
	.thumb
	.thumb_func
	.type func_0805F904, %function
func_0805F904: @ 0805F904
	push {r4, r5, r6, lr}
	movs r1, #0x00
	ldr r6, _0805F938 @ =0x02034A1C
	movs r5, #0x00
_0805F90C:
	movs r2, #0x00
	lsls r0, r1, #0x05
	adds r4, r1, #0x1
	adds r0, r0, r1
	lsls r3, r0, #0x02
_0805F916:
	ldr r0, [r6, #0x00]
	adds r0, r3, r0
	lsls r1, r2, #0x01
	adds r0, r0, r1
	strh r5, [r0, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x3C
	bls _0805F916
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x13
	bls _0805F90C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0805F938: .4byte 0x02034A1C
.syntax divided
