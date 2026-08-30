.syntax unified
	.align 2, 0
	.global task_poo_tanpopo_0
	.thumb
	.thumb_func
	.type task_poo_tanpopo_0, %function
task_poo_tanpopo_0: @ 080CF4A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r7, #0x44]
	ldr r0, [r1, #0x04]
	str r0, [r7, #0x48]
	movs r4, #0x00
	str r4, [r7, #0x4C]
	ldrh r0, [r1, #0x10]
	adds r1, r7, #0x0
	adds r1, #0xB6
	movs r2, #0x00
	mov r8, r2
	strh r0, [r1, #0x00]
	ldr r5, _080CF550 @ =0x09EF6130
	adds r0, r5, #0x0
	movs r1, #0x02
	bl func_08003524
	adds r1, r7, #0x0
	adds r1, #0xB2
	strh r0, [r1, #0x00]
	ldr r6, _080CF554 @ =0x09EF613C
	adds r0, r6, #0x0
	movs r1, #0x06
	bl func_08003524
	adds r1, r7, #0x0
	adds r1, #0xB4
	strh r0, [r1, #0x00]
	str r4, [r7, #0x04]
	adds r4, r7, #0x0
	adds r4, #0x0C
	ldr r1, _080CF558 @ =0x09EF6138
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r7, #0x08]
	adds r4, #0x20
	ldr r1, _080CF55C @ =0x09EF6154
	adds r0, r4, #0x0
	adds r2, r6, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r7, #0x28]
	adds r0, r7, #0x0
	adds r0, #0x54
	ldr r1, [r7, #0x44]
	movs r3, #0xC0
	lsls r3, r3, #0x05
	adds r1, r1, r3
	ldr r2, [r7, #0x48]
	movs r3, #0x80
	lsls r3, r3, #0x05
	adds r2, r2, r3
	ldr r3, [r7, #0x4C]
	bl func_08012324
	adds r0, r7, #0x0
	adds r0, #0xB0
	mov r1, r8
	strb r1, [r0, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CF550: .4byte 0x09EF6130
_080CF554: .4byte 0x09EF613C
_080CF558: .4byte 0x09EF6138
_080CF55C: .4byte 0x09EF6154
.syntax divided
