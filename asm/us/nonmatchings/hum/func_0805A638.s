.syntax unified
	.align 2, 0
	.global func_0805A638
	.thumb
	.thumb_func
	.type func_0805A638, %function
func_0805A638: @ 0805A638
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r0, r5, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_0805A55C
	lsls r0, r0, #0x10
	ldr r1, _0805A68C @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	cmp r0, #0x00
	bge _0805A654
	movs r2, #0x00
_0805A654:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x0C
	ble _0805A65E
	movs r2, #0x0C
_0805A65E:
	ldr r1, _0805A690 @ =0x09EDE3FC
	lsls r0, r2, #0x10
	asrs r0, r0, #0x0E
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldr r4, _0805A694 @ =0x02034934
	lsls r2, r5, #0x01
	adds r2, r2, r5
	lsls r2, r2, #0x07
	adds r2, #0x60
	ldr r1, [r4, #0x00]
	adds r1, r1, r2
	bl func_08065B6C
	ldr r1, [r4, #0x00]
	movs r2, #0xC6
	lsls r2, r2, #0x04
	adds r1, r1, r2
	adds r1, r1, r5
	strb r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_0805A68C: .4byte 0xFFFF0000
_0805A690: .4byte 0x09EDE3FC
_0805A694: .4byte 0x02034934
.syntax divided
