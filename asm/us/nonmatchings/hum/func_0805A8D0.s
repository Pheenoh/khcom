.syntax unified
	.align 2, 0
	.global func_0805A8D0
	.thumb
	.thumb_func
	.type func_0805A8D0, %function
func_0805A8D0: @ 0805A8D0
	push {r4, r5, lr}
	add sp, #-0x010
	ldr r5, _0805A940 @ =0x02034934
	ldr r0, [r5, #0x00]
	ldr r2, _0805A944 @ =0x00000C72
	adds r1, r0, r2
	ldr r3, _0805A948 @ =0x00000C74
	adds r0, r0, r3
	ldrh r4, [r1, #0x00]
	ldrh r0, [r0, #0x00]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl func_0805A484
	ldr r5, [r5, #0x00]
	ldr r1, _0805A94C @ =0x00000C78
	adds r0, r5, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _0805A950 @ =0x00000C76
	adds r1, r5, r3
	movs r2, #0x00
	ldsh r1, [r1, r2]
	adds r3, #0x3E
	adds r2, r5, r3
	lsls r4, r4, #0x10
	asrs r4, r4, #0x0E
	ldr r2, [r2, #0x00]
	adds r2, r2, r4
	movs r3, #0x00
	str r3, [sp, #0x000]
	ldr r4, _0805A954 @ =0x00000CAE
	adds r3, r5, r4
	movs r4, #0x00
	ldsh r3, [r3, r4]
	str r3, [sp, #0x004]
	movs r4, #0xCB
	lsls r4, r4, #0x04
	adds r3, r5, r4
	movs r4, #0x00
	ldsh r3, [r3, r4]
	str r3, [sp, #0x008]
	ldr r3, _0805A958 @ =0x00000CB2
	adds r5, r5, r3
	movs r4, #0x00
	ldsh r3, [r5, r4]
	str r3, [sp, #0x00C]
	movs r3, #0x00
	bl func_0805A698
	add sp, #0x010
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805A940: .4byte 0x02034934
_0805A944: .4byte 0x00000C72
_0805A948: .4byte 0x00000C74
_0805A94C: .4byte 0x00000C78
_0805A950: .4byte 0x00000C76
_0805A954: .4byte 0x00000CAE
_0805A958: .4byte 0x00000CB2
.syntax divided
