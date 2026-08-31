.syntax unified
	.align 2, 0
	.global task_poo_owl_0
	.thumb
	.thumb_func
	.type task_poo_owl_0, %function
task_poo_owl_0: @ 080CE024
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	ldr r0, _080CE08C @ =0x00041500
	str r0, [r7, #0x24]
	ldr r0, _080CE090 @ =0x00020700
	str r0, [r7, #0x28]
	ldr r0, _080CE094 @ =0xFFFFD000
	str r0, [r7, #0x2C]
	movs r4, #0x00
	str r4, [r7, #0x30]
	ldr r6, _080CE098 @ =0x09EF5DC4
	adds r0, r6, #0x0
	movs r1, #0x12
	bl func_08003524
	adds r1, r7, #0x0
	adds r1, #0x4C
	movs r5, #0x00
	strh r0, [r1, #0x00]
	str r4, [r7, #0x04]
	ldr r0, _080CE09C @ =0x09746EDC
	str r0, [r7, #0x08]
	adds r0, r7, #0x0
	adds r0, #0x0C
	ldr r1, _080CE0A0 @ =0x09EF5E24
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r7, #0x0
	adds r0, #0x48
	strb r5, [r0, #0x00]
	adds r0, #0x01
	strb r5, [r0, #0x00]
	ldr r4, _080CE0A4 @ =0x02034E08
	ldr r0, _080CE0A8 @ =0x0003FD00
	str r0, [r4, #0x00]
	ldr r0, _080CE0AC @ =0x00021B00
	str r0, [r4, #0x04]
	adds r5, r7, #0x0
	adds r5, #0x34
	adds r0, r5, #0x0
	movs r1, #0x01
	bl TaskPoolInit
	ldr r1, _080CE0B0 @ =0x09EF49B8
	adds r0, r5, #0x0
	adds r2, r4, #0x0
	bl TaskCreate
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CE08C: .4byte 0x00041500
_080CE090: .4byte 0x00020700
_080CE094: .4byte 0xFFFFD000
_080CE098: .4byte 0x09EF5DC4
_080CE09C: .4byte 0x09746EDC
_080CE0A0: .4byte 0x09EF5E24
_080CE0A4: .4byte 0x02034E08
_080CE0A8: .4byte 0x0003FD00
_080CE0AC: .4byte 0x00021B00
_080CE0B0: .4byte 0x09EF49B8
.syntax divided
