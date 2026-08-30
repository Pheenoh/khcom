.syntax unified
	.align 2, 0
	.global func_080066F4
	.thumb
	.thumb_func
	.type func_080066F4, %function
func_080066F4: @ 080066F4
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r0, _0800671C @ =0x02034058
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08006728
	ldr r1, _08006720 @ =0x02034050
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	negs r0, r0
	strh r0, [r1, #0x00]
	ldr r1, _08006724 @ =0x02034052
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	negs r0, r0
	strh r0, [r1, #0x00]
	b _08006748
_0800671C: .4byte 0x02034058
_08006720: .4byte 0x02034050
_08006724: .4byte 0x02034052
_08006728:
	ldr r3, _08006750 @ =0x02034050
	ldr r0, _08006754 @ =0x02034040
	ldr r2, [r0, #0x00]
	ldrh r1, [r2, #0x10]
	lsls r1, r1, #0x02
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	strh r1, [r3, #0x00]
	ldr r3, _08006758 @ =0x02034052
	ldrh r1, [r2, #0x12]
	lsls r1, r1, #0x02
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	strh r1, [r3, #0x00]
_08006748:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08006750: .4byte 0x02034050
_08006754: .4byte 0x02034040
_08006758: .4byte 0x02034052
.syntax divided
