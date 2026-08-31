.syntax unified
	.align 2, 0
	.global task_btl_start_0
	.thumb
	.thumb_func
	.type task_btl_start_0, %function
task_btl_start_0: @ 08031AEC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	ldr r0, _08031B5C @ =0x09EDA918
	movs r1, #0x78
	movs r2, #0x48
	bl func_08006778
	movs r4, #0x80
	lsls r4, r4, #0x02
	movs r0, #0x00
	adds r1, r4, #0x0
	adds r2, r4, #0x0
	bl func_0800675C
	ldr r6, _08031B60 @ =0x02039B84
	ldr r0, [r6, #0x00]
	movs r5, #0xE2
	lsls r5, r5, #0x01
	adds r0, r0, r5
	ldrh r0, [r0, #0x00]
	movs r1, #0x10
	movs r2, #0x10
	bl func_080057A0
	movs r2, #0x80
	lsls r2, r2, #0x09
	movs r3, #0xA0
	lsls r3, r3, #0x09
	movs r0, #0x01
	adds r1, r4, #0x0
	bl func_08019050
	movs r0, #0x00
	movs r1, #0x3C
	bl func_08006120
	movs r0, #0x00
	mov r1, r8
	strh r0, [r1, #0x00]
	movs r0, #0x8F
	bl m4aSongNumStart
	ldr r0, [r6, #0x00]
	adds r0, r0, r5
	ldrh r0, [r0, #0x00]
	movs r1, #0x00
	bl SetBgPriority
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08031B5C: .4byte 0x09EDA918
_08031B60: .4byte 0x02039B84
.syntax divided
